#ifndef HTESTRUNNER_TESTING_H
#define HTESTRUNNER_TESTING_H

#include <algorithm>
#include <array>
#include <functional>
#include <print>
#include <string_view>

namespace testing {

template <std::size_t N, class Char = char> struct static_string {
    std::array<Char, N> data;

    constexpr static_string() = default;

    constexpr explicit(false) static_string(const char (&_data)[N + 1]) {
        std::copy_n(_data, N, data.begin());
    }

    constexpr explicit(false) static_string(std::string_view sv) { std::copy_n(sv.begin(), N, data); }

    constexpr explicit(false) operator std::string_view() const { return std::string_view{ data.begin(), N }; }

    template <class R> requires(std::same_as<std::ranges::range_value_t<R>, Char>)
    constexpr bool operator==(const R& range) const {
        return std::ranges::equal(*this, range);
    }

    constexpr std::size_t size() const { return N; }

    template <std::size_t M> constexpr static_string<N + M> operator+(const static_string<M>& rhs) const {
        static_string<N + M> r;
        auto it = std::copy_n(data.begin(), N, r.data.begin());
        std::copy_n(rhs.data.begin(), M, it);
    }
};

template <std::size_t N> static_string(const char (&_data)[N]) -> static_string<N - 1>;

class controller {
    using test_function_type = void(controller&);

    std::string_view test_name;
    std::function<test_function_type> func;
    std::size_t failures = 0;

public:
    template <std::invocable<controller&> Func>
    constexpr controller(const std::string_view _name, Func&& _func)
        : test_name{ _name }, func{ std::forward<Func>(_func) } { }

    template <template <class> class Checker = std::equal_to, class L, class R>
    constexpr bool expect(const L& actual, const R& expected, const std::string_view expr) {
        if (!Checker<L>{ }(actual, expected)) {
            std::print(stderr,
                       "    failed: {}\n"
                       "    expected: {}\n"
                       "    actual: {}\n",
                       expr,
                       expected,
                       actual);
            failures++;
            return false;
        }
#ifndef VERBOSE_TESTS
        else
        {
            std::println("    passed: {}", expr);
            if constexpr (!std::is_same_v<std::decay_t<L>, bool>) {
                std::println("        value: {}\n", actual);
            }
        }
#endif
        return true;
    }

    constexpr std::size_t operator()() {
        func(*this);
        return failures;
    }

    constexpr const std::string_view name() const { return test_name; }
};

extern std::vector<controller> all_tests;

template <static_string Name> struct test_impl {
    static constexpr auto _name = Name;

    template <std::invocable<controller&> Func> explicit(false) inline test_impl(Func&& _func) {
        all_tests.emplace_back(controller{ Name, std::forward<Func>(_func) });
    }
};

// i feel like i need to explain this insanity real quick - since test units are registered in the all_tests
// vector during static initialization, the order in which they are added is undefined. practically they will
// usually go in the order they are defined, but in case we need to ensure one test runs after another, it's
// enough to access the dependency's test_impl, but it's not enough to just reference the type. this,
// shockingly, seemed like the cleanest way to reference the name and discard it while still allowing for the
// clean lambda syntax the TEST macro uses.
template <std::size_t N, std::invocable<testing::controller&> Func>
constexpr auto operator|(const testing::static_string<N> after, Func&& _func) {
    (void)after;
    return std::forward<Func>(_func);
}

/**
 * Defines a test unit. May specify up to one optional dependency which will be forced to run before this one.
 */
#define TEST(name, ...)                                                                                      \
    extern const testing::test_impl<#name>                                                                   \
        test_##name = __VA_OPT__((test_##__VA_ARGS__)._name |)[](testing::controller & _controller)->void
#define EXPECT_TRUE(cond) (_controller.expect(static_cast<bool>((cond)), true, #cond))
#define STATIC_EXPECT_TRUE(cond)                                                                             \
    static_assert(cond);                                                                                     \
    EXPECT_TRUE(cond)

/**
 * Expects the given comparison to succeed. `actual` and `expected` must be references to types satisfying
 * std::is_convertible_v and `comparison` must be a type name such that `comparison<T>{ }(actual, expected)`
 * is a well-formed expression that returns `bool`, such as `std::equal_to`.
 */
#define EXPECT(actual, comparison, expected)                                                                 \
    _controller.expect<comparison>(actual, expected, #actual " " #comparison " " #expected)

#define STATIC_EXPECT(actual, comparison, expected)                                                          \
    static_assert(comparison{}(actual, expected));                                                           \
    EXPECT(actual, comparison, expected)

#define REQUIRE_TRUE(cond)                                                                                   \
    do {                                                                                                     \
        if (!EXPECT_TRUE(cond))                                                                              \
            return;                                                                                          \
    } while (0)

#define REQUIRE(actual, comparison, expected)                                                                \
    do {                                                                                                     \
        if (!EXPECT(actual, comparison, expected)) {                                                         \
            return;                                                                                          \
        }                                                                                                    \
    } while (0)

} // namespace testing

#endif


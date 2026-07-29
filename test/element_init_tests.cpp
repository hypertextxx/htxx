#include "testing.h"
#include <functional>
#include <htxx/element.h>
#include <htxx/html.h>
#include <htxx/css.h>
#include <htxx/html_formatter.h>

template <class ...A> struct test_element: element<test_element<A...>> {
    constexpr test_element(A ...a): test_element::element{ a... } { }
    constexpr test_element() = default;
};

TEST(ElementInit) {
    static constexpr test_element el{ 123 };
    STATIC_EXPECT(el.count_children(), std::equal_to, 1);
};

TEST(HtmlInit) {
    using namespace ml;
    using namespace std::string_view_literals;
    static constexpr auto el = html{ 
        body{ 
            "hello!"sv
        }
    };
    STATIC_EXPECT(el.count_children(), std::equal_to, 1);
    std::println("{}", el);
};

TEST(HtmlWithStyle) {
    using namespace ml;
    using namespace css;
    using namespace std::string_view_literals;

    static constexpr auto el = html{
        body{
            "a link below me:"sv,
            ml::a{ $href = "#"sv, "anchor"sv },
            ml::div{ $id = "test-div"sv, $class = "test-div-class"sv, $style($padding_top = "100px", css::$height = "20px"), "text inside div"sv }
        }
    };
    std::println("{}", el);
    STATIC_EXPECT_TRUE(true);
};


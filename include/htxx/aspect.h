#ifndef HTXX_ASPECT_H
#define HTXX_ASPECT_H

#include <functional>
#include <meta> 
#include "static_string.h"

template <class T, class Gen> struct aspect {
    using value_type = T;
    value_type value;

    constexpr aspect(): value{ } { };
    template <class ...A> constexpr aspect(A&& ...a): value{ std::forward<A>(a)... } { }
    constexpr aspect(const aspect& other) requires std::copy_constructible<T> = default;
    constexpr aspect(aspect&& other) noexcept requires std::move_constructible<T>: value{ std::move(other.value) } { }

    constexpr auto operator=(const aspect& other) { 
        this->value = other.value;
    }

    static constexpr std::string_view name() {
        return Gen::name();
    }

    static consteval auto generator_info() {
        return ^^Gen;
    }

    constexpr explicit(false) operator value_type(this auto& self) { return self.value; }

    template <const auto& G, class Func> constexpr auto map(this auto& self, Func&& func) {
        if constexpr (std::is_same_v<Gen, std::decay_t<decltype(G)>>) {
            if constexpr (std::invocable<Func, decltype(self.value)&>) {
                return std::invoke(std::forward<Func>(func), self.value);
            }
        }
    }
};

template <std::meta::info VTp, static_string Name> struct aspect_generator { 
    template <class ...Args> constexpr decltype(auto) operator()(Args&& ...args) const {
        // fixed now, see gcc.gnu.org/bugzilla/show_bug.cgi?id=124706
        typename[:VTp:] r{ std::forward<Args>(args)... };
        return aspect<decltype(r), aspect_generator>{ std::move(r) };
    }

    template <class T> constexpr decltype(auto) operator=(T&& t) const {
        return this->operator()(std::forward<T>(t));
    }

    constexpr auto operator+() const requires (is_constructible_type(VTp, { ^^bool })) {
        return this->operator()(true);
    }
    
    constexpr auto operator-() const requires (is_constructible_type(VTp, { ^^bool })) {
        return this->operator()(false);
    }

    consteval std::meta::info operator!() const {
        if constexpr (is_template(VTp)) {
            return VTp;
        }
        return substitute(^^aspect, { VTp, ^^aspect_generator<VTp, Name> });
    }
    
    static constexpr std::string_view name() { return Name; }
    static consteval std::meta::info type_info() { return VTp; }

    template <std::meta::info RVTp, static_string RName> constexpr auto operator==(const aspect_generator<RVTp, RName>&) const {
        return RVTp == VTp && RName == Name;
    }
};

consteval bool is_aspect_type(std::meta::info info) {
    return std::meta::has_template_arguments(info) && std::meta::template_of(info) == ^^aspect;
}

consteval bool is_aspect_generator_type(std::meta::info info) {
    return std::meta::has_template_arguments(info) && std::meta::template_of(info) == ^^aspect_generator;
}
template <class A> concept aspect_gen_type = is_aspect_generator_type(dealias(^^A));

template <class A> concept aspect_type = is_aspect_type(dealias(^^A));

template <aspect_type A> using aspect_value_type = typename A::value_type;
template <aspect_type A> constexpr auto aspect_name = A::name();

consteval auto get_generator_info(std::meta::info aspect_info) {
    if (is_aspect_type(aspect_info)) {
        return template_arguments_of(aspect_info)[1];
    }
    throw std::meta::display_string_of(aspect_info);
}

template <class ...Gen> struct permit {
    std::array<std::meta::info, sizeof...(Gen)> gens;
    
    constexpr permit(Gen& ..._gens): gens{ ^^Gen... } { }
};

template <std::size_t N> struct format_as {
    static_string<N> identifier;

    constexpr format_as(const char (&_identifier)[N + 1]): identifier{ _identifier } { }
};
template <std::size_t N> format_as(const char (&_identifier)[N]) -> format_as<N - 1>;

template <class T, aspect_gen_type Gen> struct impermissible_aspect { };

#endif


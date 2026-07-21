#ifndef HTXX_HTML_FORMATTER_H
#define HTXX_HTML_FORMATTER_H

#include "htxx/idl_interface.h"
#include <format>

template <class ...T> struct std::formatter<std::variant<T...>> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    constexpr auto format(const std::variant<T...>& v, std::format_context& ctx) const {
        v.visit([&](const auto& x){ ctx.advance_to(std::format_to(ctx.out(), "{}", x)); });
        return ctx.out();
    }
};

template <aspect_type ...A> struct std::formatter<style<A...>> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    constexpr auto format(const style<A...>& el, std::format_context& ctx) const {
        template for (aspect_type auto& a : el.aspects()) {
            ctx.advance_to(std::format_to(ctx.out(), "{}: {}; ", aspect_name<std::decay_t<decltype(a)>>, a.value));
        }
        return ctx.out();
    }
};

template <html_element_type E> struct std::formatter<E> {
    unsigned int depth{ };

    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    constexpr auto format(const E& el, std::format_context& ctx) const {
        static constexpr auto tag_name = identifier_of(template_of(^^E));
        ctx.advance_to(std::format_to(ctx.out(), "{:{}.{}s}<{}", " ", depth * 2, depth * 2, tag_name));
        template for (aspect_type auto& a : el.aspects()) {
            static constexpr std::meta::info gen_info = get_generator_info(dealias(^^std::decay_t<decltype(a)>));
            static constexpr std::meta::info value_type_or_template = dealias(extract<std::meta::info>(template_arguments_of(gen_info)[0]));
            ctx.advance_to(std::format_to(ctx.out(), " {}=", [:gen_info:]::name()));
            if constexpr (value_type_or_template == ^^std::string_view || value_type_or_template == ^^style) {
                ctx.advance_to(std::format_to(ctx.out(), "\"{}\"", a.value));
            } else {
                ctx.advance_to(std::format_to(ctx.out(), "{}", a.value));
            }
        }
        *(ctx.out()++) = '>';

        static constexpr bool compact = E::count_children() == 0 || (E::count_children() == 1 && std::convertible_to<decltype(el.template child<0>()), std::string_view>);
        
        template for (auto& c : el.children()) {
            if constexpr (compact) {
                ctx.advance_to(std::format_to(ctx.out(), "{}", c));
            } else {
                *(ctx.out()++) = '\n';
                if constexpr (html_element_type<std::decay_t<decltype(c)>>) {
                    std::formatter<std::decay_t<decltype(c)>> cf{ depth + 1 };
                    ctx.advance_to(cf.format(c, ctx));
                } else {
                    ctx.advance_to(std::format_to(ctx.out(), "{:{}.{}s}{}", " ", (depth + 1) * 2, (depth + 1) * 2, c)); 
                }
            }
        }

        if constexpr (!compact) {
            ctx.advance_to(std::format_to(ctx.out(), "\n{:{}.{}s}", " ", depth * 2, depth * 2));
        }
        ctx.advance_to(std::format_to(ctx.out(), "</{}>", tag_name));
        return ctx.out();
    }
};

#endif


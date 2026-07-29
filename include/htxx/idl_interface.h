#ifndef HTXX_IDL_INTERFACE_H
#define HTXX_IDL_INTERFACE_H

#include "htxx/aspect.h"
#include "htxx/element.h"
#include "htxx/static_string.h"
namespace ml {

template <static_string Name> struct idl_interface {

}; 
}

template <class E> concept html_element_type = element_type<E> and std::derived_from<E, ml::idl_interface<"HTMLElement">>;

template <class ...A> struct style: element<style<A...>> {
    constexpr style() = default;
    constexpr style(A ...a): style::element{ std::move(a)... } {
        
    }
};

inline constexpr aspect_generator<^^style, "style"> $style;
inline constexpr aspect_generator<^^std::string_view, "id"> $id;
inline constexpr aspect_generator<^^std::string_view, "class_name", [][[=format_name("class")]]{}> $class;

#endif


cmake_minimum_required(VERSION 3.25)
project(htxx CXX)

set(CMAKE_CXX_STANDARD 26)

set(HTXX_IDLTOOL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/idltool")
set(HTXX_HTML_INCLUDE_DIR "${CMAKE_BINARY_DIR}/idl_include/")
file(MAKE_DIRECTORY "${HTXX_HTML_INCLUDE_DIR}")
file(MAKE_DIRECTORY "${HTXX_HTML_INCLUDE_DIR}/htxx/")
file(MAKE_DIRECTORY "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated")
add_custom_command(
    OUTPUT "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated/aspects.def" "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated/elements.def" "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated/style.def"
    COMMAND "npm" ARGS "start" "--" "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated"
    DEPENDS "${HTXX_IDLTOOL_DIR}/index.ts" "${HTXX_IDLTOOL_DIR}/csstool.ts"
    WORKING_DIRECTORY "${HTXX_IDLTOOL_DIR}"
)
add_custom_target(htxx_html_build DEPENDS "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated/aspects.def" "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated/elements.def" "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated/style.def")

add_library(htxx_html INTERFACE)
add_dependencies(htxx_html htxx_html_build)
target_include_directories(htxx_html INTERFACE "${HTXX_HTML_INCLUDE_DIR}")

add_library(htxx INTERFACE)
target_include_directories(htxx INTERFACE "include/")
target_compile_options(htxx INTERFACE "-freflection")
target_link_libraries(htxx INTERFACE htxx_html)

add_subdirectory(test/)


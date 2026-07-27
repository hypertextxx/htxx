cmake_minimum_required(VERSION 3.25)
project(htxx CXX)

set(CMAKE_CXX_STANDARD 26)

set(HTXX_IDLTOOL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/idltool")
set(HTXX_HTML_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/")
file(MAKE_DIRECTORY "${HTXX_HTML_INCLUDE_DIR}")
file(MAKE_DIRECTORY "${HTXX_HTML_INCLUDE_DIR}/htxx/")
file(MAKE_DIRECTORY "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated")
add_custom_command(
    OUTPUT "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated/aspects.h" "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated/elements.h" "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated/style.h"
    COMMAND "npm" ARGS "start" "--" "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated"
    DEPENDS "${HTXX_IDLTOOL_DIR}/index.ts" "${HTXX_IDLTOOL_DIR}/csstool.ts"
    WORKING_DIRECTORY "${HTXX_IDLTOOL_DIR}"
)
add_custom_target(htxx_html_build DEPENDS "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated/aspects.h" "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated/elements.h" "${HTXX_HTML_INCLUDE_DIR}/htxx/_generated/style.h")

add_library(htxx INTERFACE)
target_include_directories(htxx INTERFACE "include/")
target_compile_options(htxx INTERFACE "-freflection")

add_subdirectory(test/)


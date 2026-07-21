set(CMAKE_CXX_STANDARD 26)
add_executable(htxx_tests testing.cpp element_init_tests.cpp)
target_link_libraries(htxx_tests PUBLIC htxx)


add_custom_target(test COMMAND "$<TARGET_FILE:htxx_tests>")


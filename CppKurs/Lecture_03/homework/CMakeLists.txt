cmake_minimum_required(VERSION 3.13)
project(homework3)

set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!

add_library(html_writer STATIC
            api/html_writer.hpp
            src/html_writer.cpp)
target_include_directories(html_writer PRIVATE api/ fmt-7.1.3/include/)
target_link_libraries(html_writer PRIVATE /usr/lib/libfmt.a)
# target_include_directories(html_writer PRIVATE fmt-7.1.3/include/)


add_library(image_browser STATIC
            api/image_browser.hpp
            src/image_browser.cpp)
target_include_directories(image_browser PRIVATE api/)



add_executable(test_html_writer src/test.cpp)
target_include_directories(test_html_writer PRIVATE api/)
target_link_libraries(test_html_writer PRIVATE html_writer)

add_executable(test_image_browser src/test_image_browser.cpp)
target_include_directories(test_image_browser PRIVATE api/)
target_link_libraries(test_image_browser PRIVATE image_browser html_writer)


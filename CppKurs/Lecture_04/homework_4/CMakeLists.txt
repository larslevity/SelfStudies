cmake_minimum_required(VERSION 3.13)
project(homework4)

set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!

add_library(ipb_algorithm STATIC
            src/ipb_algorithm.cpp)
target_include_directories(ipb_algorithm PRIVATE include/ )



# add_library(image_browser STATIC
#             api/image_browser.hpp
#             src/image_browser.cpp)
# target_include_directories(image_browser PRIVATE api/)



add_executable(homework_4 src/main.cpp)
target_include_directories(homework_4 PRIVATE include/)
target_link_libraries(homework_4 PRIVATE ipb_algorithm)

# add_executable(test_image_browser src/test_image_browser.cpp)
# target_include_directories(test_image_browser PRIVATE api/)
# target_link_libraries(test_image_browser PRIVATE image_browser html_writer)


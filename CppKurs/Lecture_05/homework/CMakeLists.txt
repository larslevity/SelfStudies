cmake_minimum_required(VERSION 3.13)
project(homework5)

set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!

find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


# add_library(mylib STATIC
#             src/ipb_algorithm.cpp)
# target_include_directories(mylib PRIVATE include/ )

# target_link_libraries(mylib ${OpenCV_LIBS}) ## link opencv libs


add_library(mat_serialization STATIC
            src/serialize.cpp)
target_include_directories(mat_serialization PRIVATE include/)
target_link_libraries(mat_serialization ${OpenCV_LIBS})


add_executable(homework_5 src/main.cpp)
target_include_directories(homework_5 PRIVATE include/)
target_link_libraries(homework_5 ${OpenCV_LIBS} mat_serialization)


# add_executable(test_image_browser src/test_image_browser.cpp)
# target_include_directories(test_image_browser PRIVATE api/)
# target_link_libraries(test_image_browser PRIVATE image_browser html_writer)


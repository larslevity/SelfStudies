cmake_minimum_required(VERSION 3.10)
project(lecture_01)

set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!

add_library(some_file some_file.cpp)
add_executable(programm programm.cpp)
target_link_libraries(programm some_file)
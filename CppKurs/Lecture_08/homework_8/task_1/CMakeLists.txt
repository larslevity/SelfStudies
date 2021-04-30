cmake_minimum_required(VERSION 3.13)
project(homework_8_t1)

set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!


# Build main
add_executable(stack_limit main.cpp)


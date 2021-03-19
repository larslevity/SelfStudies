cmake_minimum_required(VERSION 3.13)
project(homework4)

set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!

# include(../../cmake/StaticAnalyzers.cmake)

add_executable(notes notes.cpp)
target_link_libraries(notes -lstdc++fs)

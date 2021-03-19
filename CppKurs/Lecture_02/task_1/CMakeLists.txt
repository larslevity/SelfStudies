cmake_minimum_required(VERSION 3.13)
project(homework2_task1)

set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!

# add_library(libipb_arithmetic src/sum.cpp src/subtract.cpp)
# target_include_directories(libipb_arithmetic PRIVATE include/)

add_executable(task_1 src/main.cpp)
# target_link_libraries(cmake_main libipb_arithmetic)
# target_include_directories(cmake_main PRIVATE include/)

cmake_minimum_required(VERSION 3.13)
project(homework_8_t2)

set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIRS})


# Build own libs


add_library(strategies SHARED  src/IoStrategy.cpp)
target_include_directories(strategies PRIVATE include/)
target_link_libraries(strategies -lstdc++fs ${PNG_LIBRARIES})

add_library(image SHARED src/Image.cpp )
target_include_directories(image PRIVATE include/)
target_link_libraries(image strategies)


# build main

add_executable(main src/main.cpp)
target_include_directories(main PRIVATE include/)
target_link_libraries(main 
                image)




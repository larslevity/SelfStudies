cmake_minimum_required(VERSION 3.13)
project(homework_8_t2_test)

set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIRS})
find_package(GTest REQUIRED)

set(TEST_BINARY ${PROJECT_NAME}_test)

# Build own libs


add_library(strategies SHARED  ../src/IoStrategy.cpp)
target_include_directories(strategies PRIVATE ../include/)
target_link_libraries(strategies -lstdc++fs ${PNG_LIBRARIES})

add_library(image SHARED ../src/Image.cpp )
target_include_directories(image PRIVATE ../include/)
target_link_libraries(image strategies)


add_executable(${TEST_BINARY}
               test_init.cpp
               test_from_png.cpp
               test_from_ppm.cpp
               test_resize.cpp)
target_include_directories(${TEST_BINARY} PRIVATE ../include/)

target_link_libraries(${TEST_BINARY} image GTest::Main)
gtest_discover_tests(${TEST_BINARY} WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR})

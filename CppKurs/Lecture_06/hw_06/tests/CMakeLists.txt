
cmake_minimum_required(VERSION 3.13)
project(homework6_test)

find_package(GTest REQUIRED)

set(TEST_BINARY ${PROJECT_NAME}_test)

# Build own libs

add_library(iotools SHARED ../io_tools/io_tools.cpp)
target_include_directories(iotools PRIVATE ../io_tools/)

add_library(image SHARED ../src/homework_6.cpp)
target_include_directories(image PRIVATE ../api/ ../io_tools/)
target_link_libraries(image iotools)


add_executable(${TEST_BINARY}
               test_init.cpp
               test_histogram.cpp
               test_from_file.cpp
               test_resize.cpp)

target_include_directories(${TEST_BINARY} PRIVATE ../io_tools/ ../api/)

target_link_libraries(${TEST_BINARY} image GTest::Main)
gtest_discover_tests(${TEST_BINARY} WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR})

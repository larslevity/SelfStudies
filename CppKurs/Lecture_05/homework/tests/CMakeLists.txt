cmake_minimum_required(VERSION 3.13)


set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!

find_package(Catch2 REQUIRED)
include(CTest)
include(Catch)

find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

# Build own libs
add_library(sifts_internal SHARED sifts_internal.cpp)
target_link_libraries(sifts_internal ${OpenCV_LIBS})

# find lib from homework
find_library(mat_serialization mat_serialization ../build)
find_library(convert_dataset convert_dataset ../build)

# build main
set(TEST_BINARY ${PROJECT_NAME}_test)
add_executable(${TEST_BINARY}
               test_serialize.cpp
               test_convert_dataset.cpp
               test_main.cpp)

target_include_directories(${TEST_BINARY} PRIVATE 
               ../include)
target_link_libraries(${TEST_BINARY}
                      ${convert_dataset}
                      ${mat_serialization}
                      sifts_internal
                      Catch2::Catch2
                      stdc++fs  # filesystems
                      )


catch_discover_tests(${TEST_BINARY} WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR})

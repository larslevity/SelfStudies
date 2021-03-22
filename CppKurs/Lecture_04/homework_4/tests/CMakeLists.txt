cmake_minimum_required(VERSION 3.13)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!
set(CMAKE_CXX_STANDARD 17)  # -std=c++17



find_package(Catch2 REQUIRED)
include(CTest)
include(Catch)


# add_library(ipb_algorithm STATIC
#             ../src/ipb_algorithm.cpp)
# target_include_directories(ipb_algorithm PRIVATE ../include)


find_library(ipb_algorithm_lib ipb_algorithm ../build)

set(TEST_BINARY ${PROJECT_NAME}_test)
add_executable(${TEST_BINARY}
               test_named_vector.cpp
               test_ipb_algorithm.cpp
               test_main.cpp)

target_include_directories(${TEST_BINARY} PRIVATE ../include)
target_link_libraries(${TEST_BINARY} ${ipb_algorithm_lib})


target_link_libraries(${TEST_BINARY} Catch2::Catch2)
catch_discover_tests(${TEST_BINARY})

cmake_minimum_required(VERSION 3.13)
project(homework_7_test)


set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!

find_package(GTest REQUIRED)
find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


# Build own libs
add_library(sifts_internal SHARED ../src/sifts_internal.cpp)
target_include_directories(sifts_internal PRIVATE ../include/)
target_link_libraries(sifts_internal ${OpenCV_LIBS})

add_library(serialization STATIC ../src/serialize.cpp)
target_include_directories(serialization PRIVATE ../include/)
target_link_libraries(serialization 
        ${OpenCV_LIBS}
        stdc++fs
        )

add_library(convert_dataset STATIC ../src/convert_dataset.cpp)
target_include_directories(convert_dataset PRIVATE ../include/)
target_link_libraries(convert_dataset 
        ${OpenCV_LIBS} # opencv stuff
        stdc++fs  # filesystems
        sifts_internal # compute sifts
        serialization
        )

add_library(kMeans STATIC ../src/kMeans.cpp)
target_include_directories(kMeans PRIVATE ../include/)
target_link_libraries(kMeans 
        ${OpenCV_LIBS})

add_library(bow_dictionary STATIC ../src/BowDictionary.cpp ../src/serialize.cpp)
target_include_directories(bow_dictionary PRIVATE ../include/)
target_link_libraries(bow_dictionary 
        serialization
        convert_dataset
        kMeans
        sifts_internal
        ${OpenCV_LIBS})



# builds main

add_executable(test_kmeans test_kmeans.cpp test_data.cpp)
target_include_directories(test_kmeans PRIVATE ../include/)
target_link_libraries(test_kmeans kMeans GTest::Main)
gtest_discover_tests(test_kmeans WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_bow_dictionary test_bow_dictionary.cpp)
target_include_directories(test_bow_dictionary PRIVATE ../include/)
target_link_libraries(test_bow_dictionary
                      bow_dictionary
                      serialization
                      GTest::Main)
gtest_discover_tests(test_bow_dictionary WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR})

cmake_minimum_required(VERSION 3.13)
project(homework_7)

set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!

find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Build own libs
add_library(sifts_internal SHARED src/sifts_internal.cpp)
target_include_directories(sifts_internal PRIVATE include/)
target_link_libraries(sifts_internal ${OpenCV_LIBS})

add_library(mat_serialization STATIC src/serialize.cpp src/BowDictionary.cpp)
target_include_directories(mat_serialization PRIVATE include/)
target_link_libraries(mat_serialization 
        ${OpenCV_LIBS}
        stdc++fs
        )

add_library(convert_dataset STATIC src/convert_dataset.cpp)
target_include_directories(convert_dataset PRIVATE include/)
target_link_libraries(convert_dataset 
        ${OpenCV_LIBS} # opencv stuff
        stdc++fs  # filesystems
        sifts_internal # compute sifts
        mat_serialization
        )

add_library(kMeans STATIC src/kMeans.cpp)
target_include_directories(kMeans PRIVATE include/)
target_link_libraries(kMeans 
        ${OpenCV_LIBS})

add_library(test_data STATIC src/test_data.cpp)
target_include_directories(test_data PRIVATE include/)
target_link_libraries(test_data 
        ${OpenCV_LIBS})


# Build main
add_executable(homework_7 src/main.cpp)
target_include_directories(homework_7 PRIVATE include/)
target_link_libraries(homework_7 
        ${OpenCV_LIBS} 
        mat_serialization 
        convert_dataset
        kMeans
        test_data
        stdc++fs
        )



add_executable(kmeans_example src/kmeans_example.cpp)
target_link_libraries(kmeans_example 
        ${OpenCV_LIBS} 
        )


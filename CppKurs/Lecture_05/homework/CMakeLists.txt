cmake_minimum_required(VERSION 3.13)
project(homework5)

set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!

find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Build own libs
add_library(sifts_internal SHARED src/sifts_internal.cpp)
target_include_directories(sifts_internal PRIVATE include/)
target_link_libraries(sifts_internal ${OpenCV_LIBS})

add_library(mat_serialization STATIC src/serialize.cpp)
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


# Build main
add_executable(homework_5 src/main.cpp)
target_include_directories(homework_5 PRIVATE include/)
target_link_libraries(homework_5 
        ${OpenCV_LIBS} 
        mat_serialization 
        convert_dataset
        stdc++fs
        )




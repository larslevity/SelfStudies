cmake_minimum_required(VERSION 3.13)
project(homework6)

set(CMAKE_CXX_STANDARD 17)  # -std=c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # important!



# Build own libs


add_library(iotools SHARED io_tools/io_tools.cpp)
target_include_directories(iotools PRIVATE io_tools/)

add_library(images SHARED src/homework_6.cpp)
target_include_directories(images PRIVATE api/ io_tools/)
target_link_libraries(images iotools)


add_executable(main main.cpp)
target_include_directories(main PRIVATE api/ io_tools/ src/)
target_link_libraries(main -lstdc++fs
                    images)



# # Build own libs
# add_library(sifts_internal SHARED src/sifts_internal.cpp)
# target_include_directories(sifts_internal PRIVATE include/)
# target_link_libraries(sifts_internal ${OpenCV_LIBS})

# add_library(mat_serialization STATIC src/serialize.cpp)
# target_include_directories(mat_serialization PRIVATE include/)
# target_link_libraries(mat_serialization 
#         ${OpenCV_LIBS}
#         stdc++fs
#         )

# add_library(convert_dataset STATIC src/convert_dataset.cpp)
# target_include_directories(convert_dataset PRIVATE include/)
# target_link_libraries(convert_dataset 
#         ${OpenCV_LIBS} # opencv stuff
#         stdc++fs  # filesystems
#         sifts_internal # compute sifts
#         mat_serialization
#         )


# # Build main
# add_executable(homework_5 src/main.cpp)
# target_include_directories(homework_5 PRIVATE include/)
# target_link_libraries(homework_5 
#         ${OpenCV_LIBS} 
#         mat_serialization 
#         convert_dataset
#         stdc++fs
#         )
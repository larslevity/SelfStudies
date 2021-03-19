#include "some_file.hpp"

// Manual build:

// To build this you need to link the static library "lib_some_files.a"!:
// clang++-7 programm.cpp -L . -l_some_files -o programm
// Note that "-L . -l_some_files" means:
// Linker, search in this direcory for a static library with the name "lib_some_files.a"
//      Note the difference between the two names of command and file!

// To build the static library from the *.cpp file run the following commands:
// clang++-7 -std=c++17 -c some_file.cpp -o some_file.o
// ar rcs lib_some_files.a some_file.o


// Build with cmake:

// Create "CMakeLists.txt"
// mkdir build
// cd build/
// cmake ..
// make


int main(){
    SomeFunc(10);
    return 0;
}
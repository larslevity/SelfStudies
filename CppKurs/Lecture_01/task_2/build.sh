#!/usr/bin/env bash
echo "build static libraries"
gcc -std=c++17 -c -I ./include/ src/subtract.cpp -o results/lib/subtract.o


gcc -std=c++17 -c -I ./include/ src/sum.cpp -o results/lib/sum.o
ar rcs results/lib/libipb_arithmetic.a results/lib/subtract.o results/lib/sum.o



echo "compile main.cpp"
clang++-7 src/main.cpp -std=c++17 -I ./include/ -L ./results/lib/ -lipb_arithmetic  -o results/bin/main


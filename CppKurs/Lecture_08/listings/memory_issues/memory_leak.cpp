// @file      memory_leak.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#include <iostream>
using std::cout;
using std::endl;

int main() {
  int *ptr_1 = nullptr;
  int *ptr_2 = nullptr;

  // Allocate memory for two bytes on the heap.
  ptr_1 = new int;
  ptr_2 = new int;
  cout << "1: " << ptr_1 << " 2: " << ptr_2 << endl;

  // Overwrite ptr_2 and make it point where ptr_1
  ptr_2 = ptr_1;

  // ptr_2 overwritten, no chance to access the memory.
  cout << "1: " << ptr_1 << " 2: " << ptr_2 << endl;
  delete ptr_1;
  delete ptr_2;
  return 0;
}

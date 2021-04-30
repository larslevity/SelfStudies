// @file       wrong_unique.cpp
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Igor Bogoslavskyi , all rights reserved
#include <iostream>
#include <memory>
int main() {
  // Allocate a variable in the stack
  int a = 42;

  // Create a pointer to that part of the memory
  int* ptr_to_a = &a;

  // Know stuff about pointers eh?
  auto a_unique_ptr = std::unique_ptr<int>(ptr_to_a);

  // Same happens with std::shared_ptr.
  auto a_shared_ptr = std::shared_ptr<int>(ptr_to_a);

  std::cout << "Program terminated correctly!!!\n";
  return 0;
}

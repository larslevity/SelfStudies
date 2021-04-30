// @file       shared_ptr_example.cpp
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Igor Bogoslavskyi , all rights reserved
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

class MyClass {
 public:
  MyClass() { cout << "I'm alive!\n"; }
  ~MyClass() { cout << "I'm dead... :(\n"; }
};

int main() {
  auto a_ptr = std::make_shared<MyClass>();
  cout << a_ptr.use_count() << endl;
  {
    auto b_ptr = a_ptr;
    cout << a_ptr.use_count() << endl;
  }
  cout << "Back to main scope\n";
  cout << a_ptr.use_count() << endl;
  return 0;
}

// @file       const_ptrs.cpp
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Igor Bogoslavskyi , all rights reserved
struct MyType {
  int a = 0;
};

// clang-format off
int main() {
MyType var, var_other;
// Cannot change value, can reassign pointer.
const MyType* const_var_ptr = &var;
const_var_ptr = &var_other;
// Cannot reassign pointer, can change value.
MyType* const var_const_ptr = &var;
var_const_ptr->a = 10;
// Cannot change in any way, read-only.
const MyType* const const_var_const_ptr = &var;
return 0;
}
// clang-format on

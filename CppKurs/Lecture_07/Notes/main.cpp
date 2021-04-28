#include <iostream>

// C-Style arrays:

// length is fix!
// Type array_name[length];
// Type array_name[length] = {n0, n1, n2, ..., nX};
// Type array_name[] = {n0, n1, n2, ..., nX};

int main() {
  int shorts[5] = {5, 4, 3, 2, 1};
  char chars[6] = {"hallo"};
  std::cout << chars << std::endl;

  // Pointer
  // is a own type that holds the address of a memory and the type of the stuff
  // that is at that location of the memory. Never declare a pointer without
  // initialization! Otherwise the memory will be interpreted as the type with
  // which the pointer is declared:
  int* ptr;             // bad
  int* ptr2 = nullptr;  // good

  //   std::cout << "null pointer:" << *ptr2 << std::endl;  // segmentation
  //   fault
  std::cout << "undefined pointer:" << *ptr << std::endl;  // random behaviour

  int a = 42;
  int* a_ptr = &a;

  std::cout << "a pointer:" << a_ptr << std::endl;
  std::cout << "a ref:" << *a_ptr << std::endl;

  // *ptr -> dereferencing of a pointer, i.e., gives the value of the memory the
  // ptr points to.

  return 0;
}

#include <iostream>
using std::cout;
using std::endl;
int main() {
  int size = 2;
  int *ptr = nullptr;
  {
    ptr = new int[size];
    ptr[0] = 42;
    ptr[1] = 13;
  } // End of scope does not free heap memory!
  // Correct access, variables still in memory.
  for (int i = 0; i < size; ++i) {
    cout << ptr[i] << endl;
  }
  delete[] ptr; // Free memory.
  for (int i = 0; i < size; ++i) {
    // Accessing freed memory. UNDEFINED!
    cout << ptr[i] << endl;
  }
  return 0;
}

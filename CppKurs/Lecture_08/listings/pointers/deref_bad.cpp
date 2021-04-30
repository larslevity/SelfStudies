#include <iostream>
using std::cout;
using std::endl;
int main() {
  int* i_ptr;  // BAD! Never leave unitialized!
  cout << "ptr address: " << i_ptr << endl;
  cout << "value under ptr: " << *i_ptr << endl;
  i_ptr = nullptr;
  cout << "new ptr address: " << i_ptr << endl;
  cout << "ptr size: " << sizeof(i_ptr) << " bytes";
  cout << " (" << sizeof(i_ptr) * 8 << "bit) " << endl;
  return 0;
}

#include "homework_4.h"
// #include "ipb_algorithm.cpp"
#include "utils.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  ipb::named_vector<float> my_vec;
  my_vec.vec = {1.0, 2.0, 3.0, 4.0, 5.0, 6.2222, 8.0};
  my_vec.name_ = "my vector!";
  my_vec.resize(10);
  utils::Print(my_vec.vec);
  cout << my_vec.vec[0] << endl;

  cout << "size: " << my_vec.size() << endl;
  cout << "capacity: " << my_vec.capacity() << endl;

  cout << "accumulate: " << ipb::accumulate(my_vec) << endl;

  ipb::named_vector<int> my_vec2("vec2", {1, 2, 3, 4, 5, -4, 6});
  utils::Print(my_vec2.vec);
  ipb::clamp(my_vec2, 0, 3);
  ipb::print(my_vec2);
  cout << ipb::find(my_vec2, 4) << endl;

  return 0;
}
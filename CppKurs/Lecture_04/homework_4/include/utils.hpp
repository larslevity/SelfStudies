#include <iostream>

namespace utils {

template <class Container> void Print(const Container &v) {
  for (auto n : v) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
}
}; // namespace utils

#include "homework_4.h"
#include <algorithm>
#include <iostream>
#include <numeric>

namespace ipb {

inline bool even(int i) { return i % 2 == 0; }

template <typename T> T accumulate(named_vector<T> &vec) {
  return std::accumulate(vec.vec.cbegin(), vec.vec.cend(), 0);
}
template int accumulate(named_vector<int> &vec);
template float accumulate(named_vector<float> &vec);

template <typename T> int count(named_vector<T> &vec, int target) {
  return std::count(vec.vec.cbegin(), vec.vec.cend(), target);
}
template int count(named_vector<int> &vec, int target);

template <typename T> bool all_even(named_vector<T> &vec) {
  return std::all_of(vec.vec.cbegin(), vec.vec.cend(), even);
}
template bool all_even(named_vector<int> &vec);

template <typename T> void clamp(named_vector<T> &vec, T min, T max) {
  for (T &d : vec.vec) {
    d = std::min(std::max(d, min), max);
  }
}
template void clamp(named_vector<int> &vec, int min, int max);

template <typename T> void fill(named_vector<T> &vec, T val) {
  std::fill(vec.vec.begin(), vec.vec.end(), val);
}
template void fill(named_vector<int> &vec, int val);

template <typename T> bool find(named_vector<T> &vec, T val) {
  auto result = std::find(vec.vec.cbegin(), vec.vec.cend(), val);
  return result != vec.vec.end();
}
template bool find(named_vector<int> &vec, int val);

template <typename T> void print(named_vector<T> &vec) {
  std::cout << vec.name() << ": ";
  for (const auto &elem : vec.vec) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}
template void print(named_vector<int> &vec);

auto UpperCase(char c) { return std ::toupper(c); }
template <typename T> void toupper(named_vector<T> &vec) {
  std::transform(vec.name_.begin(), vec.name_.end(), vec.name_.begin(),
                 UpperCase);
}
template void toupper(named_vector<int> &vec);

template <typename T> void sort(named_vector<T> &vec) {
  std::sort(vec.vec.begin(), vec.vec.end());
}
template void sort(named_vector<int> &vec);

template <typename T> void rotate(named_vector<T> &vec, int increment) {
  std::rotate(vec.vec.begin(), vec.vec.begin() + increment, vec.vec.end());
}
template void rotate(named_vector<int> &vec, int increment);

template <typename T> void reverse(named_vector<T> &vec) {
  std::reverse(vec.vec.begin(), vec.vec.end());
}
template void reverse(named_vector<int> &vec);

}; // namespace ipb
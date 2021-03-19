#include <string>
#include <vector>

#pragma once

namespace ipb {

template <typename T> struct named_vector {
  std::vector<T> vec;
  std::string name_;

  named_vector(std::string n, std::vector<T> v) {
    vec = v;
    name_ = n;
  }
  named_vector() {}

  std::string name() { return name_; }
  std::vector<T> vector() { return vec; }

  bool empty() { return (vec.size() == 0 || name_.size() == 0) ? true : false; }
  int size() { return vec.size() + name_.size(); }
  int capacity() { return vec.capacity(); }
  void reserve(unsigned int new_cap) { vec.reserve(new_cap); }
  void resize(unsigned int count) { vec.resize(count); }
};

template <typename T> T accumulate(named_vector<T> &vec);
template <typename T> int count(named_vector<T> &vec, int target);
template <typename T> bool all_even(named_vector<T> &vec);
template <typename T> void clamp(named_vector<T> &vec, T min, T max);
template <typename T> void fill(named_vector<T> &vec, T val);
template <typename T> bool find(named_vector<T> &vec, T val);
template <typename T> void print(ipb::named_vector<T> &vec);
template <typename T> void toupper(ipb::named_vector<T> &vec);
template <typename T> void sort(ipb::named_vector<T> &vec);
template <typename T> void rotate(ipb::named_vector<T> &vec, int increment);
template <typename T> void reverse(ipb::named_vector<T> &vec);

}; // namespace ipb
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;

void Print(const std::array<int, 10> data) {
  for (const auto &elem : data) {
    cout << elem << " ";
  }
  cout << endl;
}

inline bool even(int i) { return i % 2 == 0; }

int main() {
  cout << "\n\nCONTAINERS\n============\n";
  // Containers provided by the STL-Lib: (Standard Template Library)
  // ============
  // Containers are implemented for example as: array or vector
  // They provide the standard functions:
  // size(), empty(), front(), back(), swap(), STL-Algorithms, ...

  // Arrays:
  // arrays are static (defined during compile time): array<TYPE, SIZE>
  // Access items with: arr[i]
  std::array<float, 3> data{10.0F, 2.0F, 1000.0F};

  for (const auto &elem : data) {
    cout << elem << endl;
  }
  cout << std::boolalpha;
  cout << "Array empty: " << data.empty() << endl;
  cout << "Array size:  " << data.size() << endl;

  // Vectors:
  // Vectors dynamic (defined during runtime):
  // vector<TYPE> = {data1, data2, ...}
  // Access items with: vec[i]
  std::vector<int> numbers = {1, 2, 3};
  std::vector<std::string> names = {"Lars", "Mila"};

  names.emplace_back("Milena Rizo"); // increase size of vector (append)

  cout << "Last name: " << names.back() << endl;
  cout << "First number:" << numbers.front() << endl;

  // Drawback of vectors -> size unknown
  // Therefore vec.capacity is defined -> max size
  //  size neq capacity.
  // capacity can be changed with reserve command
  // Good Example:
  const int N = 100;
  std::vector<int> vec; // size 0 , capacity 0
  vec.reserve(N);
  for (int i = 0; i < N; ++i) {
    vec.emplace_back(i);
  }; // ends with size 100 capacity 100
  cout << "Size, Capacity: " << vec.size() << ", " << vec.capacity() << endl;

  // Bad Example
  std::vector<int> vec2;
  for (int i = 0; i < N; ++i) {
    vec2.emplace_back(i);
  }
  cout << "Size, Capacity: " << vec2.size() << ", " << vec2.capacity() << endl;

  // Exploring the size of a container:
  std::array<int, 17> data1{};
  cout << "Size of Array: " << data1.size() << endl;
  // Clear elements of container:
  std::vector<int> vec3 = {1, 2, 3, 4, 5, 6};
  cout << "Vec3 before clear(): " << endl;
  for (const auto &elem : vec3) {
    cout << elem << " ";
  }
  vec3.clear();
  cout << "\nVec3 after clear():  " << endl;
  for (const auto &elem : vec3) {
    cout << elem << " ";
  }

  // Associative Containers
  // ===========================
  // Example: map (key/value pairs -- like python dict)
  // keys are stored using the "<" operator as they are sorted
  // -> keys should be comparable -> use built-in types as int or float
  std::map<int, std::string> example_map{{2, "World"}, {1, "Hello, "}};
  example_map.emplace(0, "Test: ");
  for (const auto &[key, val] : example_map) {
    cout << val << endl;
  }
  // Check if key is present:
  cout << "Is key '3' present? " << (example_map.count(3) > 0) << endl;
  // Better syntax with c++20:
  // cout << "Is key '2' present? " << example_map.contains(2) << endl;

  // There is a faster, unordered map:
  std::unordered_map<int, std::string> example_map2{{1, "eins"}, {0, "null"}};
  example_map2.emplace(55, "Test: ");
  for (const auto &[key, val] : example_map2) {
    cout << val << endl;
  }
  // For unordered_map the key must be hashable! If built-in types are used this
  // is already implemented. It is also possible to use self made type keys, but
  // then the hash function must also be provided!!

  // ITERATORS
  // ==========================
  // Minimize dependence of an algorithm from the data structure it is apllied
  // to. Iterators are defined for all STL-containers.
  // Interface between algorithms and data!
  cout << "\n\nITERATORS\n============\n";
  std::vector<double> x{1, 2, 3, 100};
  for (auto it = x.begin(); it != x.end(); ++it) {
    cout << *it << endl;
  }

  // STL-Algorithm
  // ==========================
  // Dont reinvent the wheel. Use standard algos!
  // When using slef-made containers, just provide the implementation for
  // standard iterators and you will gain access to all standard algorithms :)
  cout << "\n\nSTL-Algorithms\n============\n";
  std::array<int, 10> s{1, 2, 3, 100, -3, 4, -8, 33, 22};

  // Sort
  std::sort(s.begin(), s.end());
  for (const auto &elem : s) {
    cout << elem << " ";
  }
  cout << endl;

  // Find n1
  const int n1 = 34;
  auto result1 = std::find(s.begin(), s.end(), n1);
  // Result is an iterator. If tis iterator is equal to the end of the
  // container, the serached element is not in the container:
  cout << n1 << " in container?: " << (result1 != s.end() ? true : false)
       << endl;

  // Fill a container:
  std::fill(s.begin(), s.end(), 42);
  for (const auto &elem : s) {
    cout << elem << " ";
  }
  cout << endl;
  Print(s);

  // count occurence:
  cout << "Occurence of 42: " << std::count(s.begin(), s.end(), 42) << endl;
  cout << "Occurence of 10: " << std::count(s.begin(), s.end(), 10) << endl;

  // for_each:
  auto print = [](const int &n) { cout << " " << n; };
  std::for_each(vec.cbegin(), vec.cend(), print);
  cout << endl;

  // all_of:
  s[3] = 44;
  bool all_even = std::all_of(s.cbegin(), s.cend(), even);
  cout << "All elements of 's' are even?: " << all_even << endl;

  // rotate:
  // Shifts positions in array

  // Transform:
  // for example make upper case string from lower case string

  // Accumulate:
  // Building the sum, or product of all elements in container

  // minmax_element
  auto [min, max] =
      std::minmax_element(vec.cbegin(), vec.cend()); // Returns pointer!!
  cout << "min, max: " << *min << ", " << *max << endl;

  // clamp
  // clamp a value between min and max val -- saturate
  const double kMax = 1.0F;
  const double kMin = 0.0F;
  cout << std::clamp(2.1, kMin, kMax) << endl;
  cout << std::clamp(0.966, kMin, kMax) << endl;

  // sample
  // randomly pick 5 letters from a string
  std::string in = "C++ is sooo cool!!!";
  std::string out;
  auto rnd_dev = std::mt19937{std::random_device{}()};
  const int kNLetters = 5;
  std::sample(in.begin(), in.end(), std::back_inserter(out), kNLetters,
              rnd_dev);
  cout << "input:  " << in << endl;
  cout << "output: " << out << endl;
}

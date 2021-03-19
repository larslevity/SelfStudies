#include <chrono>      // benchmarking in terms of timings
#include <cstdlib>     // comes with filesystem demo
#include <filesystem>  // creating dirs / inspect path
#include <fstream>     // reading and writing to files
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using std::cout;
using std::endl;

namespace fs = std::filesystem;

int main() {
  // compile with: clang++-7 -std=c++17 notes.cpp
  cout << "BASIC C++ UTILITIES" << endl;
  cout << "===================" << endl << endl;

  // ===========================================
  cout << "Tuples:" << endl;
  cout << "-------" << endl;

  using my_tuple = std::tuple<int, char, std::string>;
  my_tuple t1{1, 'A', "hello world!"};
  my_tuple t2{2, 'B', "hello world!"};
  cout << std::get<std::string>(t1) << endl;
  cout << std::get<2>(t1) << endl;  // same
  // c++17 style:
  auto [int_val, char_val, str_val] = t1;

  cout << int_val << char_val << str_val << endl;

  // ===========================================
  cout << endl << "chrono: (e.g. use for timing benchmarking)" << endl;
  cout << "-------" << endl;
  auto start = std::chrono::steady_clock::now();
  cout << "Do fancy operation ..." << endl;
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> sec = end - start;
  cout << "elapsed time: " << sec.count() << "s" << endl;

  // ===========================================
  cout << endl << "I/O library: (reading and writing to files)" << endl;
  cout << "-------" << endl;
  auto start2 = std::chrono::steady_clock::now();
  // Sytanx is same as cerr or cout

  // ofstream: stream for output to file
  std::string filename = "out.txt";
  std::ofstream f_out(filename, std::ios_base::out);

  f_out << "Hello world" << endl;

  // ifstream: stream for input from file
  std::string s;
  int a;
  double b;
  std::ifstream f_in("in.txt", std::ios_base::in);
  while (f_in >> s >> a >> b) {
    f_out << s << ", " << a << ", " << b << endl;
  }
  auto end2 = std::chrono::steady_clock::now();
  std::chrono::duration<double> sec2 = end2 - start2;
  f_out << "elapsed time: " << sec2.count() << "s" << endl;

  // fstream: stream for input from file
  // std::fstream f_in_out(std::string & file_name, Mode
  // std::ios_base::trunc);

  // more complex input files:
  std::string line, filename2;
  std::ifstream input("complex_in.txt", std::ios_base::in);
  // Read data line wise
  while (std::getline(input, line)) {
    cout << "Read: " << line << endl;
    // string has find method:
    std::string::size_type loc = line.find("filename", 0);
    if (loc != std::string::npos) {
      filename2 = line.substr(line.find("=====", 0) + 1, std::string::npos);
    }
  }
  cout << "Filename found: " << filename2 << endl;

  // Some example on printing to files with defined prescision. in lecture

  // ===========================================
  cout << endl << "Serialization: reading and writing binary files" << endl;
  cout << "-------" << endl;

  // Writing to binary files:
  std::string imgname = "000000.dat";
  std::ofstream img_out(imgname, std::ios_base::out | std::ios_base::binary);
  int rows = 2;
  int cols = 5;
  std::vector<float> vec(rows * cols);
  for (float d : vec) {
    cout << d << " ";
  }
  cout << endl;
  vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (float d : vec) {
    cout << d << " ";
  }
  cout << endl;
  img_out.write(reinterpret_cast<char *>(&rows), sizeof(rows));
  img_out.write(reinterpret_cast<char *>(&cols), sizeof(cols));
  img_out.write(reinterpret_cast<char *>(&vec.front()),
                vec.size() * sizeof(float));
  img_out.close();

  // Reading from binary files: (does not work ...:/   )
  int r = 0, c = 0;
  std::ifstream img_in(imgname, std::ios_base::in | std::ios_base::binary);
  if (!img_in) {
    return EXIT_FAILURE;
  }
  img_in.read(reinterpret_cast<char *>(&r), sizeof(r));
  img_in.read(reinterpret_cast<char *>(&c), sizeof(c));
  cout << "Dimensions: " << r << " x " << c << endl;
  std::vector<float> data(r * c);
  img_in.read(reinterpret_cast<char *>(&data.front()),
              data.size() * sizeof(data.front()));
  img_in.close();
  for (float d : data) {
    cout << d << " ";
  }
  cout << endl;

  // ===========================================
  cout << endl
       << "Filesystem library (operations on paths, files, directories)"
       << endl;
  cout << "-------" << endl;
  //   fs::current_path(fs::temp_directory_path());
  fs::create_directories("../sandbox/a/b");
  for (auto &p : fs::directory_iterator("..")) {
    cout << p.path() << endl;
  }

  return 0;
}
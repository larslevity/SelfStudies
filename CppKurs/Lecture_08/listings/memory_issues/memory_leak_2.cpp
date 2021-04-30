// @file       memory_leak_2.cpp
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Igor Bogoslavskyi , all rights reserved
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

namespace {
void PrintRule() {
  cout << "=================================================================\n";
}

void PrintBanner(size_t mem) {
  PrintRule();
  cout << mem << "[Gib] are being consumed by this program\n"
       << "Open a shell and type htop to see how much memory you have left on\n"
          "your system\n"
       << "After you finished you can press <Enter> to continue\n";
  PrintRule();

  // wait for <Enter>
  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

} // namespace

int main() {
  PrintRule();
  size_t KGbToConsume = 0;
  cout << "Hello hacker, how many GiB of memory do you want to consume?\n";
  cin >> KGbToConsume;
  cin.ignore(std::numeric_limits<int>::max(), '\n');
  cout << "Alright, " << KGbToConsume << " [GiB] will be consumed...\n";
  PrintRule();

  // Now let's eat all your available memory RAM!
  double *data = nullptr;
  size_t size = pow(1024, 3) / 8; // Produce 1GB
  for (size_t i = 0; i < KGbToConsume; ++i) {
    // Allocate memory for the data.
    data = new double[size];
    std::fill(data, data + size, 1.23);
    cout << (i + 1) << " GiB has been allocated!\n";
  }

  PrintBanner(KGbToConsume);

  // This will only free the last allocation!
  cout << "Now attempting to free " << KGbToConsume << " [GiB] of memory...\n";
  delete[] data;

  PrintBanner(KGbToConsume - 1);

  return 0;
}

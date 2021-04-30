#include <iostream>

int main() {
  int size = 100;
  int size_ = size * 1024;
  for (int i = 0; i < 10000; ++i) {
    uint8_t junk[size_ * i];
    std::fill(&junk[0], &junk[size_ * i], 42);
    std::cerr << size * i << "[KiB] Allocated in the stack" << std::endl;
  }
  return 0;
}
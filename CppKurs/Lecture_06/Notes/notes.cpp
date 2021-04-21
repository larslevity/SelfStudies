
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

class Image {
 public:
  Image() = default;
  explicit Image(const std::string& filename);
  ~Image();

  bool empty() const;
  void save(const std::string& filename);

 private:
  std::vector<uint8_t> data_;
  int rows_ = 0;
  int cols_ = 0;
};

int main() {
  Image img("lenna.png");

  return 0;
}
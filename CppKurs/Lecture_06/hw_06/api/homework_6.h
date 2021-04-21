#include <string>
#include <vector>

namespace igg {

class Image {
 public:
  Image();
  Image(int rows, int cols);
  ~Image();

 public:
  int rows() const;
  int cols() const;
  uint8_t& at(const int row, const int col);
  uint8_t at(const int row, const int col) const;
  //   int& at(const int row, const int col);

  bool FillFromPgm(const std::string& file_name);
  void WriteToPgm(const std::string& file_name) const;

  std::vector<float> ComputeHistogram(int bins) const;

  void DownScale(int scale);
  void UpScale(int scale);

 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 0;
  std::vector<uint8_t> data_;
};
};  // namespace igg

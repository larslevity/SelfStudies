#include "Image.h"

#include <iostream>
#include <string>

namespace igg {

void Image::SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr) {
  strat_ = strategy_ptr;
}

bool Image::ReadFromDisk(const std::string& file_name) {
  ImageData data = strat_->ReadFromDisk(file_name);
  rows_ = data.rows;
  cols_ = data.cols;
  max_val_ = data.max_val;
  std::vector<Pixel> data_pix;

  for (auto pix : data.data) {
    data_pix.push_back(Pixel(pix));
  }
  data_ = data_pix;

  if (rows_ == 0 && cols_ == 0) {
    return false;
  }
  return true;
}

void Image::WriteToDisk(const std::string& file_name) const {
  ImageData data;
  data.rows = rows_;
  data.cols = cols_;
  data.max_val = max_val_;
  std::vector<std::array<int, 3>> data_array;
  for (auto pix : data_) {
    std::array<int, 3> rgb = {pix.red, pix.green, pix.blue};
    data_array.push_back(rgb);
  }
  data.data = data_array;
  strat_->WriteToDisk(data, file_name);
}

Image::Image() {
  rows_ = 0;
  cols_ = 0;
}
Image::Image(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  data_.resize(rows * cols);
}
Image::~Image() {}

int Image::rows() const { return rows_; }
int Image::cols() const { return cols_; }
Pixel& Image::at(const int row, const int col) {
  if (row > rows_ || col > cols_) {
    std::cout << "out of range ..." << std::endl;
  }
  return data_[row * cols_ + col];
}

Pixel Image::at(const int row, const int col) const {
  if (row > rows_ || col > cols_) {
    std::cout << "out of range ..." << std::endl;
  }
  return data_[row * cols_ + col];
}

// std::vector<float> Image::ComputeHistogram(int bins) const {
//   std::vector<float> vec(bins, 0);
//   for (const auto& value : data_) {
//     int bin = float(value - value % (255 / bins)) / 255 * bins;
//     if (bin == bins) {
//       bin -= 1;
//     }
//     vec[bin] += 1;
//     // std::cout << bin;
//   }

//   std::cout << vec[0] << std::endl;
//   for (auto& value : vec) {  // normalize
//     value = value / data_.size();
//   }

//   //   std::cout << "size of data_: " << data_.size() << "\n";

//   return vec;
// }

void Image::DownScale(int scale) {
  int rows = rows_ / scale;
  int cols = cols_ / scale;
  std::vector<igg::Pixel> data(rows * cols);
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      data[r * cols + c] = data_[r * cols_ * scale + c * scale];
    }
  }
  data_.resize(cols * rows);
  data_ = data;
  rows_ = rows;
  cols_ = cols;
}

void Image::UpScale(int scale) {
  int rows = rows_ * scale;
  int cols = cols_ * scale;
  std::vector<igg::Pixel> data(rows * cols);

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      data[r * cols + c] = data_[r / scale * cols / scale + c / scale];
    }
  }

  data_.resize(cols * rows);
  data_ = data;
  rows_ = rows;
  cols_ = cols;
}

};  // namespace igg
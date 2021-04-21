#include "homework_6.h"

#include <iostream>
#include <string>

#include "io_tools.hpp"

namespace igg {

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
uint8_t& Image::at(const int row, const int col) {
  if (row > rows_ || col > cols_) {
    std::cout << "out of range ..." << std::endl;
  }
  return data_[row * cols_ + col];
}

uint8_t Image::at(const int row, const int col) const {
  if (row > rows_ || col > cols_) {
    std::cout << "out of range ..." << std::endl;
  }
  return data_[row * cols_ + col];
}

bool Image::FillFromPgm(const std::string& file_name) {
  igg::io_tools::ImageData data;
  data = igg::io_tools::ReadFromPgm(file_name);
  rows_ = data.rows;
  cols_ = data.cols;
  max_val_ = data.max_val;
  data_ = data.data;

  if (rows_ == 0 && cols_ == 0) {
    return false;
  }
  return true;
}

std::vector<float> Image::ComputeHistogram(int bins) const {
  std::vector<float> vec(bins, 0);
  for (const auto& value : data_) {
    int bin = float(value - value % (255 / bins)) / 255 * bins;
    if (bin == bins) {
      bin -= 1;
    }
    vec[bin] += 1;
    // std::cout << bin;
  }

  std::cout << vec[0] << std::endl;
  for (auto& value : vec) {  // normalize
    value = value / data_.size();
  }

  //   std::cout << "size of data_: " << data_.size() << "\n";

  return vec;
}

void Image::WriteToPgm(const std::string& file_name) const {
  igg::io_tools::ImageData data;
  data.rows = rows_;
  data.cols = cols_;
  data.max_val = max_val_;
  data.data = data_;

  bool save = igg::io_tools::WriteToPgm(data, file_name);
}

void Image::DownScale(int scale) {
  int rows = rows_ / scale;
  int cols = cols_ / scale;
  std::vector<uint8_t> data(rows * cols);
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
  std::vector<uint8_t> data(rows * cols);

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
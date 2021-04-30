#include "IoStrategy.h"

#include <bits/stdint-uintn.h>

#include <array>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

#include <png++/png.hpp>

namespace igg {

ImageData PpmIoStrategy::ReadFromDisk(const std::string& file_name) {
  std::ifstream in(file_name, std::ios_base::in);
  if (!in) {
    std::cout << file_name << " not found..." << std::endl;
    return {0, 0, 0, {}};
  }

  // Read meta data
  std::string type;
  int rows = 0;
  int cols = 0;
  int max_val = 0;
  std::vector<std::array<int, 3>> data;
  in >> type;

  // Ignore comment line
  std::string dummy;
  in >> dummy;
  if (!dummy.compare("#")) {
    in.ignore(256, '\n');
    in >> rows;
  } else {
    rows = std::stoi(dummy);
  };

  in >> cols >> max_val;

  std::cout << "type: " << type << " "
            << "rows: " << rows << " "
            << "cols: " << cols << " "
            << "max_val: " << max_val << std::endl;

  // read data
  data.resize(rows * cols);
  int red = 0;
  int green = 0;
  int blue = 0;
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      in >> red >> green >> blue;
      std::array<int, 3> pix = {red, green, blue};
      data[r * cols + c] = pix;
    }
  }
  return {rows, cols, static_cast<uint8_t>(max_val), data};
}

bool PpmIoStrategy::WriteToDisk(const ImageData& data,
                                const std::string& file_name) {
  std::ofstream out(file_name);
  if (!out) {
    return false;
  }

  out << "P3" << std::endl
      << data.rows << " " << data.cols << std::endl
      << unsigned(data.max_val) << std::endl;
  for (int r = 0; r < data.rows; ++r) {
    for (int c = 0; c < data.cols; ++c) {
      out << unsigned(data.data[r * data.cols + c][0]) << " ";
      out << unsigned(data.data[r * data.cols + c][1]) << " ";
      out << unsigned(data.data[r * data.cols + c][2]) << " ";
    }
    out << std::endl;
  }
  return true;
}

ImageData PngIoStrategy::ReadFromDisk(const std::string& file_name) {
  png::image<png::rgb_pixel> image(file_name);
  int rows = image.get_height();
  int cols = image.get_width();
  uint8_t max_val = 0;
  std::vector<std::array<int, 3>> data;
  data.resize(rows * cols);

  std::cout << "type: PNG "
            << "rows: " << rows << " "
            << "cols: " << cols << " "
            << "max_val: " << max_val << std::endl;

  for (png::uint_32 r = 0; r < rows; ++r) {
    for (png::uint_32 c = 0; c < cols; ++c) {
      png::rgb_pixel pix = image.get_pixel(c, r);
      std::array<int, 3> array = {pix.red, pix.green, pix.blue};
      data[r * cols + c] = array;
    }
  }
  return {rows, cols, static_cast<uint8_t>(max_val), data};
}

bool PngIoStrategy::WriteToDisk(const ImageData& data,
                                const std::string& file_name) {
  png::image<png::rgb_pixel> image(data.cols, data.rows);
  for (png::uint_32 r = 0; r < data.rows; ++r) {
    for (png::uint_32 c = 0; c < data.cols; ++c) {
      int red = data.data[r * data.cols + c][0];
      int g = data.data[r * data.cols + c][1];
      int b = data.data[r * data.cols + c][2];
      image[r][c] = png::rgb_pixel(red, g, b);
    }
  }
  image.write(file_name);
  return 1;
}

}  // namespace igg
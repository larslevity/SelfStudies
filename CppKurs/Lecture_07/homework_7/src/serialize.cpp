#include "serialize.hpp"

#include <fstream>  // reading and writing to files
#include <iostream>
#include <string>
#include <vector>

#include <opencv2/core/mat.hpp>

namespace ipb::serialization {

void Serialize(const cv::Mat& m, const std::string& filename) {
  auto [cols, rows] = m.size();
  int type = m.type(), channels = m.channels();

  // Write Meta infos:
  std::ofstream out(filename, std::ios_base::out | std::ios_base::binary);
  out.write((char*)&rows, sizeof(rows));
  out.write((char*)&cols, sizeof(cols));
  out.write((char*)&type, sizeof(type));
  out.write((char*)&channels, sizeof(channels));

  // Convert to vec
  cv::Mat flat = m.reshape(1, m.total() * m.channels());
  std::vector<uchar> array = m.isContinuous() ? flat : flat.clone();
  std::vector<float> arrayf = m.isContinuous() ? flat : flat.clone();

  // Write vec
  if (type == 5) {
    out.write(reinterpret_cast<char*>(&arrayf.front()),
              arrayf.size() * sizeof(float));
  } else {
    out.write(reinterpret_cast<char*>(&array.front()),
              array.size() * sizeof(array.front()));
  }

  out.close();
}

cv::Mat Deserialize(const std::string& filename) {
  int rows = 0, cols = 0, type = 0, channels = 0;
  std::ifstream img_in(filename, std::ios_base::in | std::ios_base::binary);
  if (!img_in) {
    std::cerr << filename << " not found.\n";
  }
  // Read meta
  img_in.read((char*)(&rows), sizeof(rows));
  img_in.read((char*)(&cols), sizeof(cols));
  img_in.read((char*)(&type), sizeof(type));
  img_in.read((char*)(&channels), sizeof(channels));
  // std::cout << "Dimensions: " << cols << " x " << rows << " Type: " << type
  //           << std::endl;

  // Read vec
  if (type == 5) {  // float
    std::vector<float> array(rows * cols * channels);
    img_in.read(reinterpret_cast<char*>(&array.front()),
                array.size() * sizeof(array.front()));
    img_in.close();
    // convert to mat
    cv::Mat out = cv::Mat(rows, cols, type);
    memcpy(out.data, array.data(), array.size() * sizeof(array.front()));
    return out;
  } else {
    std::vector<uchar> array(rows * cols * channels);
    img_in.read(reinterpret_cast<char*>(&array.front()),
                array.size() * sizeof(array.front()));
    img_in.close();
    // convert to mat
    cv::Mat out = cv::Mat(rows, cols, type);
    memcpy(out.data, array.data(), array.size() * sizeof(array.front()));
    return out;
  }
}
};  // namespace ipb::serialization
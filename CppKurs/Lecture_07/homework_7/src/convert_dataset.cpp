

#include <filesystem>  // create folders ...
#include <fstream>     // read and write to files
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>

#include "homework_7.h"
#include "sifts_internal.hpp"

using std::cout;
using std::endl;
namespace fs = std::filesystem;

namespace ipb::serialization::sifts {

void ConvertDataset(const std::filesystem::path& img_path) {
  // Create List of images
  std::vector<fs::path> filenames;
  for (auto& p : fs::directory_iterator(img_path)) {
    // cout << p.path() << endl;
    if (p.path().extension() == ".png") filenames.push_back(p.path());
  }
  fs::path bin_path = img_path / "../bin";
  fs::create_directories(bin_path);

  // Compute Sift for each image and write to bin
  std::vector<cv::Mat> image_with_keypoints_vec;

  for (auto& filename : filenames) {
    // compute sifts
    const auto [descriptors, image_with_kp, kp] = ComputeSifts(filename);
    image_with_keypoints_vec.push_back(image_with_kp);

    // write descriptors
    fs::path filename_bin = bin_path / filename.stem();
    filename_bin += ".bin";
    cout << filename_bin << endl;
    ipb::serialization::Serialize(descriptors, filename_bin);
  }
  // Test: Show keypoint images
  for (int i = 0; i < 2; ++i) {
    cv::imshow(filenames[i], image_with_keypoints_vec[i]);
  }
}

std::vector<cv::Mat> LoadDataset(const std::filesystem::path& bin_path) {
  // Create List of binary images
  std::vector<fs::path> filenames_bin;
  for (auto& p : fs::directory_iterator(bin_path)) {
    if (p.path().extension() == ".bin") filenames_bin.push_back(p.path());
  }
  // Read and de-serialize each image
  std::vector<cv::Mat> out;
  for (auto& filename : filenames_bin) {
    cv::Mat m = ipb::serialization::Deserialize(filename);
    out.push_back(m);
  }

  return out;
}

}  // namespace ipb::serialization::sifts
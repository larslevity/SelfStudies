#include <filesystem>
#include <iostream>
#include <string>

#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

#include "homework_7.h"
#include "sifts_internal.hpp"
#include "test_data.hpp"

using std::cout;
using std::endl;
namespace fs = std::filesystem;

int main() {
  int k = 100;  // dict_size
  int max_iter = 10;

  fs::path img_path = fs::current_path() / "../data/freiburg/images/";
  // fs::path img_path = "/home/ls/dev/datasets/images-freiburg-x10/data1";
  cout << "Image path:  " << img_path << endl;
  // ipb::serialization::sifts::ConvertDataset(img_path);  // compute sifts
  fs::path bin_path = img_path / "../bin/";
  auto descriptors_set = ipb::serialization::sifts::LoadDataset(bin_path);

  auto centers = ipb::kMeans(descriptors_set, k, max_iter);
  // cout << "centers of freiburg" << centers << endl;

  auto& dict = ipb::BowDictionary::GetInstance();
  cout << "dict empty? " << dict.empty() << endl;
  dict.set_params(max_iter, k, descriptors_set);
  cout << "dict empty? " << dict.empty() << endl;

  // Test Data from unit test
  std::vector<cv::Mat> dummys = GetDummyData();
  auto centroids = ipb::kMeans(dummys, k, max_iter);
  cout << "dummy centers" << centroids << endl;

  // Iterate to understand process:
  if (0) {
    for (auto& p : fs::directory_iterator(img_path)) {
      if (p.path().extension() != ".png") break;

      fs::path fileName = p.path();
      cout << fileName << endl;
      const auto [descriptors, image_with_kp, kp] = ComputeSifts(fileName);

      const cv::Mat kInput = cv::imread(fileName, cv::IMREAD_GRAYSCALE);
      cv::Mat image_with_keypoints;
      cv::drawKeypoints(kInput, kp, image_with_keypoints);

      // Convert kp to cv::Mat:
      cv::Mat kpmat(kp.size(), 2, CV_32F);
      int row = 0;
      for (auto& kp : kp) {
        kpmat.at<float>(row, 0) = kp.pt.x;
        kpmat.at<float>(row, 1) = kp.pt.y;
        row++;
      }

      // k-means of keypoints:
      cv::Mat labels;
      std::vector<cv::Point2f> centers;
      int k = 15;         // Number of centroids
      int max_iter = 10;  // max iterations of k-means
      double compactness = cv::kmeans(
          kpmat, k, labels,
          cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 10,
                           1.0),
          max_iter, cv::KMEANS_PP_CENTERS, centers);

      for (int i = 0; i < (int)centers.size(); ++i) {
        cv::Point2f c = centers[i];
        circle(image_with_keypoints, c, 40, cv::Scalar(0, 0, 255), 1,
               cv::LINE_AA);
      }

      cv::imshow(fileName, image_with_keypoints);
      cv::waitKey(0);
    }
  }

  return 0;
}

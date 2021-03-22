#include <iostream>
#include <string>

#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

#include "homework_5.h"

using std::cout;
using std::endl;

// DataType<uint>::type == CV_8UC3;  // RGB type
// Name of Datatypes in OpenCV follows a pattern:
// CV_<bitcount><identifiers><Channels>
// CV_8UC1 = 8bit unsigend char 1 channel -> Grescale image

template <typename Tp>
bool inline mat_are_equal(const cv::Mat& m1, const cv::Mat& m2) {
  return std::equal(m1.begin<Tp>(), m1.end<Tp>(), m2.begin<Tp>());
}

void MatType(cv::Mat inputMat) {
  int inttype = inputMat.type();

  std::string r, a;
  uchar depth = inttype & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (inttype >> CV_CN_SHIFT);
  switch (depth) {
    case CV_8U:
      r = "8U";
      a = "Mat.at<uchar>(y,x)";
      break;
    case CV_8S:
      r = "8S";
      a = "Mat.at<schar>(y,x)";
      break;
    case CV_16U:
      r = "16U";
      a = "Mat.at<ushort>(y,x)";
      break;
    case CV_16S:
      r = "16S";
      a = "Mat.at<short>(y,x)";
      break;
    case CV_32S:
      r = "32S";
      a = "Mat.at<int>(y,x)";
      break;
    case CV_32F:
      r = "32F";
      a = "Mat.at<float>(y,x)";
      break;
    case CV_64F:
      r = "64F";
      a = "Mat.at<double>(y,x)";
      break;
    default:
      r = "User";
      a = "Mat.at<UKNOWN>(y,x)";
      break;
  }
  r += "C";
  r += (chans + '0');
  cout << "Mat is of type " << r << " and should be accessed with " << a
       << endl;
}

int main() {
  // using Matf = cv::Mat_<float>;
  // Matf image = Matf::zeros(100, 100);
  // image.at<float>(5.5) = 42.42f;
  // //   std::string f = "test.exr";
  // //   cv::imwrite(f, image);
  // //   Matf copy = cv::imread(f, cv::IMREAD_UNCHANGED);
  // //   std::cout << copy.at(5, 5) << std::endl;

  // // ImShow:
  // std::string window_name = "Test Window";
  // cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
  // cv::imshow(window_name, image);
  // cv::waitKey(0);

  // ImShow lenna:
  // cv::Mat image_lenna = cv::imread("../data/lenna.png", cv::IMREAD_COLOR);
  cv::Mat image_lenna = cv::imread("../data/lenna.png", cv::IMREAD_GRAYSCALE);
  // cv::Mat image_lenna = cv::imread("../data/test.jpg", cv::IMREAD_COLOR);
  // cv::Mat image_lenna = cv::Mat_<float>::zeros(4, 6);
  // image_lenna.at<float>(2.2) = 2.22;
  if (image_lenna.empty()) {
    std::cerr << "Image not found..\n";
    return 1;
  }
  if (image_lenna.total() < 100) {
    std::cout << "\n";
    std::cout << "M = " << std::endl << " " << image_lenna << "\n\n";
  }
  MatType(image_lenna);

  ipb::serialization::Serialize(image_lenna, "out.bin");
  cv::Mat lenna_ = ipb::serialization::Deserialize("out.bin");

  if (image_lenna.total() < 100) {
    std::cout << "\n";
    std::cout << "M = " << std::endl << " " << lenna_ << "\n\n";
  }

  cout << "Mats are equal: " << mat_are_equal<uchar>(image_lenna, lenna_)
       << endl;

  cv::Mat rs;
  cv::resize(image_lenna, rs, cv::Size(), 10, 10);
  cv::Mat rs_;
  cv::resize(lenna_, rs_, cv::Size(), 10, 10);
  cv::imshow("original", image_lenna);
  // cv::imshow("original zoom", rs);
  cv::imshow("deserialized", lenna_);
  // cv::imshow("deserialized  zoom", rs_);
  cv::waitKey(0);

  return 0;
}

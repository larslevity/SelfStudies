#include "kMeans.hpp"

#include <iostream>
#include <vector>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

namespace ipb {

cv::Mat kMeans(const std::vector<cv::Mat>& descriptors, int k, int max_iter) {
  // Put all descriptors into a single Mat:
  cv::Mat descriptor_mat{};
  for (const auto& descriptor : descriptors) {
    descriptor_mat.push_back(descriptor);
  }

  cv::Mat labels;
  cv::Mat centriods;
  double compactness =
      cv::kmeans(descriptor_mat, k, labels, cv::TermCriteria(),
                 //  cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 10, 1.0),
                 max_iter, cv::KMEANS_RANDOM_CENTERS,
                 //  cv::KMEANS_PP_CENTERS,
                 centriods);

  //   std::cout << "descriptors: " << descriptor_mat.size() << std::endl;
  //   std::cout << "centriods: " << centriods.size() << std::endl;

  return centriods;
}
}  // namespace ipb
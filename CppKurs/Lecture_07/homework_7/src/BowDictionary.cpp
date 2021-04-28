
#include <iostream>
#include <vector>

#include "homework_7.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

template <typename Tp>
bool inline mat_are_equal(const cv::Mat &m1, const cv::Mat &m2) {
  return std::equal(m1.begin<Tp>(), m1.end<Tp>(), m2.begin<Tp>());
}

bool descriptor_are_equal(std::vector<cv::Mat> d1, std::vector<cv::Mat> d2) {
  if (d1.size() != d2.size()) return false;
  for (size_t i = 0; i < d1.size() / 2; i++) {
    if (!mat_are_equal<uint8_t>(d1[i], d2[i])) return false;
  }
  return true;
}

namespace ipb {

// Getters:
int BowDictionary::max_iterations() const { return max_iterations_; }
int BowDictionary::size() const { return size_; }
std::vector<cv::Mat> BowDictionary::descriptors() const { return descriptors_; }
cv::Mat BowDictionary::vocabulary() const { return vocabulary_; }
int BowDictionary::total_features() const { return total_features_; }
bool BowDictionary::empty() const { return descriptors_.empty(); }

// Setters:
void BowDictionary::set_max_iterations(const int max_iter) {
  set_params(max_iter, size_, descriptors_);
}
void BowDictionary::set_size(const int size) {
  set_params(max_iterations_, size, descriptors_);
}
void BowDictionary::set_descriptors(const std::vector<cv::Mat> &descriptors) {
  set_params(max_iterations_, size_, descriptors);
}
void BowDictionary::set_params(const int max_iter, const int size,
                               const std::vector<cv::Mat> &descriptors) {
  if (size_ != size || !descriptor_are_equal(descriptors_, descriptors) ||
      max_iterations_ != max_iter) {
    max_iterations_ = max_iter;
    size_ = size;
    descriptors_ = descriptors;

    vocabulary_ = ipb::kMeans(descriptors_, size_, max_iterations_);

    cv::Mat descriptor_mat{};
    for (const auto &descriptor : descriptors_) {
      descriptor_mat.push_back(descriptor);
    }
    total_features_ = descriptor_mat.rows;
  }
}

}  // namespace ipb
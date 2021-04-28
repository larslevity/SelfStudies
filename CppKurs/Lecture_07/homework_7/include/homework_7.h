#include <iostream>

#include "convert_dataset.hpp"
#include "kMeans.hpp"
#include "serialize.hpp"

namespace ipb {

class BowDictionary {
 private:
  BowDictionary() = default;
  ~BowDictionary() = default;

 public:
  BowDictionary(const BowDictionary &) = delete;
  void operator=(const BowDictionary &) = delete;
  BowDictionary(const BowDictionary &&) = delete;
  void operator=(const BowDictionary &&) = delete;

 public:
  // Getters:
  int max_iterations() const;
  int size() const;
  std::vector<cv::Mat> descriptors() const;
  cv::Mat vocabulary() const;
  int total_features() const;
  bool empty() const;

  // Setters:
  void set_max_iterations(const int max_iter);
  void set_size(const int size);
  void set_descriptors(const std::vector<cv::Mat> &descriptors);
  void set_params(const int max_iter, const int size,
                  const std::vector<cv::Mat> &descriptors);

  static BowDictionary &GetInstance() {
    static BowDictionary instance;
    return instance;
  }

 private:
  int max_iterations_;
  int size_;
  std::vector<cv::Mat> descriptors_;
  cv::Mat vocabulary_;
  int total_features_;
};

}  // namespace ipb

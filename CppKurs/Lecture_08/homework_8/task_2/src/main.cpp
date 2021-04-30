#include <iostream>
#include <memory>
#include <vector>

#include "homework_8.h"

using std::cout;
using std::endl;

int main() {
  igg::Image img;

  img.SetIoStrategy(std::make_shared<igg::PpmIoStrategy>());
  img.SetIoStrategy(std::make_shared<igg::PngIoStrategy>());

  // img.ReadFromDisk("../data/pbmlib.ascii.ppm");
  img.ReadFromDisk("../data/pic1.png");

  // cout << img.rows() << "  " << img.cols() << endl;

  int x = 0;
  int y = 0;

  igg::Pixel val = img.at(x, y);

  cout << unsigned(val.red) << " " << unsigned(val.green) << " "
       << unsigned(val.blue) << endl;
  img.at(x, y) = igg::Pixel(0, 0, 0);

  igg::Pixel val1 = img.at(x, y);
  cout << unsigned(val1.red) << " " << unsigned(val1.green) << " "
       << unsigned(val1.blue) << endl;

  img.DownScale(6);
  img.UpScale(2);

  img.WriteToDisk("../data/test.png");

  // igg::Image img2;
  // img2.FillFromPgm("../tests/data/dummy_file.pgm");
  // std::vector<float> hist = img2.ComputeHistogram(1);

  // for (auto val : hist) {
  //   cout << val << " ";
  // }
  // cout << endl;

  // img2.WriteToPgm("test.pgm");

  return 0;
}
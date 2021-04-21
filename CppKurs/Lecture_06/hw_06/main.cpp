#include <iostream>
#include <vector>

#include "homework_6.h"

using std::cout;
using std::endl;

int main() {
  igg::Image img;
  img.FillFromPgm("../data/lena.ascii.pgm");

  cout << img.rows() << "  " << img.cols() << endl;

  int x = 33;
  int y = 44;

  int val = img.at(x, y);

  cout << unsigned(val) << endl;
  img.at(x, y) = 255;
  cout << unsigned(img.at(x, y)) << endl;

  igg::Image img2;
  img2.FillFromPgm("../tests/data/dummy_file.pgm");
  std::vector<float> hist = img2.ComputeHistogram(1);

  for (auto val : hist) {
    cout << val << " ";
  }
  cout << endl;

  img.DownScale(6);

  img.UpScale(6);

  img2.WriteToPgm("test.pgm");

  return 0;
}
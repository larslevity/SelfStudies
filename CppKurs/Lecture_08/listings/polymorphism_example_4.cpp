
// @file      polymorphism_example.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;
using std::vector;

class Rectangle {
public:
  Rectangle(int w, int h) : width_{w}, height_{h} {}
  int width() const { return width_; }
  int height() const { return height_; }

  virtual void Print() const {
    cout << "Rec:" << width_ << " " << height_ << endl;
  }

protected:
  int width_ = 0;
  int height_ = 0;
};

class Square : public Rectangle {
public:
  explicit Square(int size) : Rectangle{size, size} {}
  void Print() const override {
    cout << "Sq:" << width_ << " " << height_ << endl;
  }
};

int main() {
  vector<unique_ptr<Rectangle>> shapes;
  shapes.emplace_back(make_unique<Rectangle>(10, 15));
  shapes.emplace_back(make_unique<Square>(10));

  for (const auto &shape : shapes) {
    shape->Print();
  }

  return 0;
}

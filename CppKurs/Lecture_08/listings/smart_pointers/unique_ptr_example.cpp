// @file      unique_ptr_example.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::string;

////////////////////////////////////////////////////////////////////////////////
class Vehicle {
 private:
  int seats_ = 0;     // number of seats on the vehicle
  int capacity_ = 0;  // amount of fuel of the gas tank
  string brand_;      // make of the vehicle

 public:
  Vehicle(int seats, int capacity, const string& brand)
      : seats_(seats), capacity_(capacity), brand_(brand) {}

  int get_seats(void) const { return seats_; }
  int get_capacity(void) const { return capacity_; }
  string get_brand(void) const { return brand_; }

  void Print(void) const {
    cout << "Vehicle seats available = " << seats_ << endl
         << "Vehicle fuel available = " << capacity_ << endl
         << "Vehicle brand = " << brand_ << endl;
  }
};

////////////////////////////////////////////////////////////////////////////////
class Bus : public Vehicle {
 public:
  Bus(int seats, int capacity, const string& brand, const string& brakes)
      : Vehicle(seats, capacity, brand), special_brakes_(brakes) {}

  string special_brakes(void) const { return special_brakes_; }

 private:
  string special_brakes_;
};

////////////////////////////////////////////////////////////////////////////////
class Car : public Vehicle {
 public:
  Car(int seats, int capacity, const string& brand, const string& stereo)
      : Vehicle(seats, capacity, brand), stereo_brand_(stereo) {}

  string stereo_brand(void) const { return stereo_brand_; }

 private:
  string stereo_brand_;
};

////////////////////////////////////////////////////////////////////////////////
// clang-format off
int main() {
// smart pointers are polymorphic, so we can create an unique_ptr to a
// 'Vehicle' and point later to the derived Type we want to use. This is
// particularry helpfull when working with containers
std::unique_ptr<Vehicle> vehicle_1 =
std::make_unique<Bus>(20, 10, "Volkswagen", "LPM_");

std::unique_ptr<Vehicle> vehicle_2 =
std::make_unique<Car>(4, 60, "Ford", "Sony");

// vehicle_x is a pointer, so we can us it as it is
vehicle_1->Print();
vehicle_2->Print();

// Let's print where these pointers are pointing to
cout << "vehicle_1 = " << vehicle_1.get() << endl;
cout << "vehicle_2 = " << vehicle_2.get() << endl;

// unique_ptr can only point to only one particular object in the heap, this
// means that the following line will fail to compile:
// ~ vehicle_2 = vehicle_1;
// We can't use vehicle_2 to point to the object that vehicle_1 is point to
// because vehicle_1 owns that object. If we want to do something like this,
// we should move the object instead.
vehicle_2 = std::move(vehicle_1);

// And now if we use the vehicle_2 pointer we will be pointing to the Bus
// instead of the Car
vehicle_2->Print();

// What about now? vehicle_2 should have the address we saw for vehicle_1 and
// this last one should point to nothing(nullptr==0)
cout << "vehicle_1 = " << vehicle_1.get() << endl;
cout << "vehicle_2 = " << vehicle_2.get() << endl;
return 0;
}
// clang-format on

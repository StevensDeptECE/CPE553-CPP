#Overview

#include <iostream>

class Shape {

    virtual double area() = 0;
};

class Circle : public Shape {
    double area()  {}
};

class Rect : public Shape {
    double area()  {}
};

class Airplane {
  public:
    void fly();
};

class PassengerPlane : public Airplane {
public:
  void serveCoffee();
};

class B707 : public PassengerAirplane {

};

class B707_22 : public PassengerAirplane {

};
class FighterPassengerPlane : public Airplane {
public:
  void shoot();
};

f();
f(2,3, "abc");

vector<int> a;
vector<PassengerAirplane> pa;

exception handling

lambda functions

vector
map
unordered_map
random
algorithm
string
regex





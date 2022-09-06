#include "derived1.hh"
#include <iostream>
/*
VFT:
  pointer to derived1::f
  pointer to derived1::g


 */


void derived1::f() {
  std::cout << "yo! I am a derived 1";
}

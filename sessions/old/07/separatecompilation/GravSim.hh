#pragma once
#include <string>
#include <vector>
#include "Body.hh"

class GravSim {
private:
  std::vector<Body> bodies;
  double dt;
public:
  GravSim(const std::string& filename, double dt);
  void simulate(double time, double printPeriod);

};

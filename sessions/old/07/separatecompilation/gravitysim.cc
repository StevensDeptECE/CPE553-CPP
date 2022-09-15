#include "GravSim.hh"

int main() {
  double dt = 3600;
  GravSim g("solarsystem.dat", dt);
  g.simulate(86400 * 365 * 100, 86400);
}


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vec3d {

};

class Body {
private:
    Vec3d pos;
    Vec3d v;
    Vec3d a;
public:
  Body( ... )
};

class SolarSystem {
private:
  vector<Body> bodies; // all bodies in the solar system

  void timeStep(double dt) {
    // for each body b
    {
        set accel = 0
    //      for each body b2
        {
    //   if b != b2
    //  
        }
    }
    //for each body b
    b.pos = b.pos + b.v * 0.5* dt + b.a * dt*dt; // d = v0*t + 1/2a*t*t
    b.v = b.v + b.a * dt;

  }
};

int main() {
    SolarSystem s("solarsystem.dat"); // this must not change
    // each body should have a random position in a circular or elliptical orbit around the sun
    // each  body should start with an appropriate velocity
    //each body should have velocity = https://en.wikipedia.org/wiki/Circular_orbit v= sqrt(GM/r)
    double earthYear = 365.2425 *  24  * 60 * 60;
    const int numTimeSteps = 1000;
    double dt = earthYear / numTimeSteps;
    for (int i = 0; i < numTimeSteps; i++)
        s.timeStep(dt);
    cout << s; // print out the state of the solar system (where each object is, location only)

    // if you do it right, earth should be in roughly the same place...


}
#include <iostream>
#include <vector>
using namespace std;

// put your Vec3d implementation here

// put your Body implementation here

class Body {
private:
	double mass;
	Vec3d pos;
	Vec3d v;
	Vec3d a;
public:
	Body() {}
	operator >>(istream& s, Body& b) {
		// read in the body from the file
		// radius of your orbit = (Perihelion  + Aphelion) /2
		// pick a random location on your orbit
		// pick  a random angle 0 to 2*pi search "c++ random uniform double example"
		// x = r *cos(ang), y = r*sin(ang)
		//  compute an initial velocity
		// Look in wikipedia
		//https://en.wikipedia.org/wiki/Circular_orbit
		// 	v = sqrt(G*mofthebodyyouareorbniting/r)
		//special case: all planets orbit the sun. the sun orbits no one
		// sun initial v = 0
	}

	static setAccelerations(vector<Body>& bodies) {
		for (auto b : bodies) {

		}
	}
};

class SolarSystem {
private:
  vector<Body> bodies;
public:
	void stepForward() {
		Body::setAccelerations(bodies);
		for (auto b : bodies) {
			// step forward in time
		}
	}
};

int main() {
	/*
	1. read in the solar system from the file
  2. Your SolarSystem class should have a list (vector) of Body objects
  3. for each row in the file, add a body. Calculate the initial position for 
     each body as last week. Note that for now we will not be giving you moons
     because they orbit not the sun but other planets. This will be added later.

  4. Each body should calculate the acceleration due to the gravitational pull
     of all the others bodies. This requires vector math, which you should write
     in Vec3d.
     For any body m, the accelation due to another body m2 is:

		 sun = (0,0,0)
     earth = (3,2,0)

		 delta = (sun-earth) = (-3,-2,0)

     dpos = pos2 - pos
     rsq = dpos.magsq()   -3*-3+-2*-2+0*0 = 13
     r = sqrt(rsq)        r = magnitude of dpos, the distance to the other body

     G = universal gravitational constant 6.667E-11

     F = G*me*m2/rsq  
		 a = F/me so mass of the earth cancels threfore:

     a = G*m2/rsq  

     To calculate the vector acceleration, you must break down a into components
     dirtootherbody = dpos.normalize() 
		 Acceltowardotherbody = (a*dirtootherbody.x, a*dirtootherbody.y, 0)
     (compute a unit vector in the direction of body2)

		 or in scalars:
     ax = a * dpos.x/r, ay = a * dpos.y/r, az = a * dpos.z/r


		 If you can do this calculation within vector, it is a generically useful
		 one but you can also just compute it in Body if you want.

		 Sum up all accelerations.

		 for each body i
       set acceleration of body i = 0
		   for each body j
         add acceleration of body j on i unless j == i
       end
     end

     when you have the acceleration of all bodies, step forward in time for a timestep dt with:

    for each body b
     b.pos = b.pos + b.v * dt + 0.5 * b.a * dt*dt
     b.v = b.v + b.a * dt;

    dt is delta time (double precision) and should not be huge. 
    Start with 1000 seconds and see what happens. If 
    one body is in a sharply changing orbit, dt may have to be reduced.
    For the above to work you will have to implement some operators in Vec3d.

	*/
  SolarSystem s("solarsystem.dat");
	cout << s << "=========\n\n\n"; // print the solar system at load time
	for (int i = 0; i < 31556; i++) {
  	s.stepForward(1000); // step forward in time by 1000 seconds
	}
	// the loop should step forward in time by about a year. We are simplifying
	// the orbit to a circle, so the numbers will be off a bit.
	cout << s << "=========\n\n\n"; // print the solar system after the year
}
	

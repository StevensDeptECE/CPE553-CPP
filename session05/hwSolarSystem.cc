#include <iostream>
#include <vector>
using namespace std;

// put your Vec3d implementation here

// put your Body implementation here

class SolarSystem {
private:
  vector<Body> bodies;
public:
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

     a = Gm2/rsq,   rsq = (pos2 - pos).magsq()
     G = universal gravitational constant

     To calculate the vector acceleration, you must break down a into components
     dpos = (pos2 - pos).normalize 
     (compute a unit vector in the direction of body2)

     ax = a * dpos.x/r, ay = a * dpos.y/r, az = a * dpos.z/r

     r = magnitude of dpos.

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


    v^2/r = a
		v = sqrt(ar)
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
	

class Vec3d {


};

class Body {
private:
	string name;
	double mass;   // mass of the body
	double radius; // size of the body (assumes spherical)
	Vec3d pos;     // pos = (x,y,0) ignore z for now. x,y should be based on orbital radius
	Vec3d v;       // v = 0 next week we have to calculate
	Vec3d a;       // a = 0 next week we compute gravitational acceleration due to all other bodies

  Body() : name(), pos(), v(), a() {}
	
  friend ostream& operator <<(ostream& s, const Body& b) {


	}

  friend istream& operator >>(istream& s, Body&  b) {


	}
};


int main() {
	ifstream solarsystem("solarsystem.dat");
	char buf[1024];
	solarsystem.getline(buf, sizeof(buf)); // throw out first line

	Body sun, mercury, venus, earth, moon;
	solarsystem >> sun >> mercury >> venus >> earth;

	// read in the name of each body
	// compute average distance of each body from sun (average of perihelion and aphelion)
	// pick t = a random number from 0 to 2*pi
	// 
	// calculate x,y = r cos t, r sin t
	// put into pos vector (x,y, 0)

	// next step (not necessary this week)
	// calculate V
	// pretend all orbits are circular
	// calculate the length of the circular path around the sun 2*pi * r
	// look up time it takes to orbit
	// convert to meters and seconds
	// v = distance around the sun / orbital period in seconds
	cout << sun << mercury << venus << earth;
}

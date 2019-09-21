class Vec3d {


};

class Body {
private:
	Vec3d pos;

};

int main() {
	ifstream solarsystem("solarsystem.dat");
	char buf[1024];
	solarsystem.getline(buf, sizeof(buf)); // throw out first line

	Body sun, mercury, venus, earth, moon;
	solarsystem >> sun >> mercury >> venus >> earth;
	// compute average distance of each body from sun (average of perihelion and aphelion)
	// pick t = a random number from 0 to 2*pi
	// 
	// calculate x,y = r cos t, r sin t

	// next step (not necessary this week)
	// calculate V
	// pretend all orbits are circular
	// calculate the length of the circular path around the sun 2*pi * r
	// look up time it takes to orbit
	// convert to meters and seconds
	// v = distance around the sun / orbital period in seconds
	cout << sun << mercury << venus << earth;
}

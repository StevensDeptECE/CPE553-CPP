class Vec3d {
public:

};


class Body {
private:

public:
	Body(double mass, const Vec3d& pos, const Vec3d& v, const Vec3d& a) {}
  
};

class SphericalBody : public Body {}; // make it work! (add radius
	
// do all operators as friend
int main() {
	const Vec3d a(1.0,2.0,3.0);
	const Vec3d b(1.5,1.2,2.1);
	Vec3d c = a + b;
	Vec3d d = a - b;
	double d1 = dot(a, b);
	double d2 = Vec3d::dot(a,b);
	double d3 = a.dot(b);
	const Vec3d e = -a; // unary -
	cout << e << '\n';
	double m = b.magSq(); // compute magnitude squared
	double m2 = b.mag(); // compute magnitude ( you should do sqrt( magSq() )

	Body earth(6.56e+24, Vec3d(0,0,0), Vec3d(0,0,0));
	double v = 0;// moon avg vel;
	Body moon(5.56e+22, Vec3d(3e8,0,0), Vec3d(0,v,0)); //
  //calculate acceleration of earth and moon	
}

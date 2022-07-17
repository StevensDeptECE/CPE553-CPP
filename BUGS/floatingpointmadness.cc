#include <iostream>
#include <iomanip>
#include <cmath>
#include <numbers>
//#include "util/Benchmark.hh"
using namespace std;
using namespace std::numbers;

/*
	Intel used to have 80 bits in-register, 64 in memory
	making results from unoptimized code different than optimized
	(Optimized was more correct, if the values were kept in-register)
	Can this still be replicated given that new hardware uses vector
	registers with 128 and 256 bits, with each number only 64 bits max?

	depends on whether gcc -march= can specify an old architecture
	pre-sse and what they do with it.

	gcc -march=x86-64
 */
void variablePrecision() {
 	float a = 0;
	for (int i = 1; i <= 100; i++)
		a += 1.0/i;
	cout << "forward float: " << setprecision(16) << a << '\n';
	a = 0;
	for (int i = 100; i > 0; i--)
		a += 1.0/i;
	cout << "backward float: " << setprecision(16) << a << '\n';
 	double b = 0;
	for (int i = 1; i <= 100; i++)
		b += 1.0/i;
	cout << "forward double: " << setprecision(16) << b << '\n';
	b = 0;
	for (int i = 100; i > 0; i--)
		b += 1.0/i;
	cout << "backward double: " << setprecision(16) << b << '\n';
}

struct Point {
  float x,y;
  Point(float x, float y) : x(x), y(y) {}
  Point() {}
	friend ostream& operator <<(ostream& s, const Point& p) {
		return s << p.x << "," << p.y;
	}
};

template<typename Precision>
Point centroid(const Precision x[], const Precision y[], int numPoints){
  double signedArea = 0;
  double cx = 0, cy = 0;
  int i;
  for (i = 0; i < numPoints-1; i++) {
    double seg = (x[i] * y[i+1] - x[i+1] * y[i]);
    signedArea += seg;
    double cxseg = (x[i] + x[i+1]) * seg;
    double cyseg = (y[i] + y[i+1]) * seg;
    cx += cxseg;
    cy += cyseg;
  }
  double seg = (x[i] * y[0] - x[0] * y[i]);
  signedArea += seg;
  double cxseg = (x[i] + x[0]) * seg;
  double cyseg = (y[i] + y[0]) * seg;
  cx += cxseg;
  cy += cyseg;
  cx /= (6/2)*signedArea;
  cy /= (6/2)*signedArea;
  return Point(cx, cy);
}

template<typename Precision>
Point centroidDelta(const Precision x[], const Precision y[],
										uint32_t numPoints){
	double basex = x[0], basey = y[0];
	double xi1 = 0, yi1 = 0;
	double xi = x[numPoints-1]-basex, yi = y[numPoints-1]-basey;
	double seg = xi * yi1 - xi1 * yi;
  double signedArea = seg;
	double cxseg = 0, cyseg = 0;
  double cx = 0, cy = 0;
  for (uint32_t i = 1; i < numPoints; i++) {
		xi = xi1, yi = yi1;
		xi1 = x[i]-basex, yi1 = y[i]-basey;
		seg = xi * yi1 - xi1 * yi;
    signedArea += seg;
		cxseg = (xi + xi1) * seg;
		cyseg = (yi + yi1) * seg;
    cx += cxseg;
    cy += cyseg;
  }
  cx /= (6/2)*signedArea;
  cy /= (6/2)*signedArea;
  return Point(basex+cx, basey+cy);
}

template<typename Precision>
Point centroidDelta_b(const Precision x[], const Precision y[],
										uint32_t numPoints){
	double basex = x[0], basey = y[0];
	double xi1 = x[1]-basex, yi1 = y[1]-basey;
	double xi, yi;
  double signedArea = 0;
  double cx = 0, cy = 0;
  for (uint32_t i = 1; i < numPoints-1; i++) {
		xi = xi1, yi = yi1;
		xi1 = x[i]-basex, yi1 = y[i]-basey;
		double seg = xi * yi1 - xi1 * yi;
    signedArea += seg;
		double cxseg = (xi + xi1) * seg;
		double cyseg = (yi + yi1) * seg;
    cx += cxseg;
    cy += cyseg;
  }
  cx /= (6/2)*signedArea;
  cy /= (6/2)*signedArea;
  return Point(basex+cx, basey+cy);
}

template<typename Precision>
double area(Precision x[], Precision y[], uint32_t numPoints){
  double signedArea = 0;
  int i;
  for (i = 0; i < numPoints-1; i++) {
		double xi = x[i], yi = y[i], xi1 = x[i+1], yi1 = y[i+1];
    signedArea += xi * yi1 - xi1 * yi;
  }
	double xi = x[i], yi = y[i], xi1 = x[0], yi1 = y[0];
  signedArea += xi * yi1 - xi1 * yi;
	return signedArea;
}

template<typename Precision>
double area_b(Precision x[], Precision y[], uint32_t numPoints){
	const uint32_t last = numPoints - 1;
	double xi = x[last], yi = y[last];
	double xi1 = x[0], yi1 = y[0];
  double signedArea = xi * yi1 - xi1 * yi;
  for (uint32_t i = 1; i < numPoints; i++) {
		xi = xi1, yi = yi1;
		xi1 = x[i], yi1 = y[i];
    signedArea += xi * yi1 - xi1 * yi;
  }
	return signedArea;
}

template<typename Precision>
double area_c(Precision x[], Precision y[], uint32_t numPoints){
	const uint32_t last = numPoints - 1;
	double basex = x[last], basey = y[last];
	double xi = 0, yi = 0; // first point is zero, use as basex
	double xi1 = x[0] - basex, yi1 = y[0] - basey;
  double first = xi * yi1, second = xi1 * yi;
  for (uint32_t i = 1; i < numPoints; i++) {
		xi = xi1, yi = yi1;
		xi1 = x[i] - basex, yi1 = y[i] - basey;
    first += xi * yi1;
		second += xi1 * yi;
  }
	return first - second;
}

Point centroid_b(const float x[], const float y[], int numPoints){
  double signedArea = 0;
  double cx = 0, cy = 0;
  int i;
	double xi, yi;
  for (i = 0; i < numPoints-1; i++) {
		xi = x[i], yi = y[i];
		const double xi1 = x[i+1], yi1 = y[i+1];
    double seg = xi * yi1 - xi1 * yi;
    signedArea += seg;
    double cxseg = (xi + xi1) * seg;
    double cyseg = (yi + yi1) * seg;
    cx += cxseg;
    cy += cyseg;
  }
  double seg = xi * y[0] - x[0] * yi;
  signedArea += seg;
  double cxseg = (xi + x[0]) * seg;
  double cyseg = (yi + y[0]) * seg;
  cx += cxseg;
  cy += cyseg;
  cx /= (6/2)*signedArea;
  cy /= (6/2)*signedArea;
  return Point(cx, cy);
}

void testExampleIsland(const double x[], const double y[], uint32_t n) {
	float xf[n], yf[n];
	for (uint32_t i = 0; i < n; i++)
		xf[i] = x[i], yf[i] = y[i];

	//	variablePrecision();

	cout << "centroid (double):      " << centroid(x,y,n) << '\n';
	cout << "centroid (float):       " << centroid(xf,yf,n) << '\n';
	cout << "centroid_b (float):     " << centroid_b(xf,yf,n) << '\n';
	cout << "centroidDelta (double): " << centroidDelta(x,y,n) << '\n';
	cout << "centroidDelta (float):  " << centroidDelta(xf,yf,n) << '\n';
}
void 	testKnownCentroid(double basex, double basey, double r, uint32_t n) {
	double x[n], y[n];
	double t = 0, dt = 2 * pi / n;
	for (int i = 0; i < n; i++, t += dt) {
		x[i] = basex + r * cos(t);
		y[i] = basey + r * sin(t);
	}	
  cout << "Testing Known Centroid at " << basex << "," << basey << " n=" << n << '\n';
	cout << "centroid (double): " << centroid(x, y, n) << '\n';
	cout << "delta (double):    " << centroidDelta(x, y, n) << '\n';

	{
		float x[n], y[n];
		double t = 0, dt = 2 * pi / n;
		for (int i = 0; i < n; i++, t += dt) {
			x[i] = basex + r * cos(t);
			y[i] = basey + r * sin(t);
		}
		cout << "centroid (float): " << centroid(x, y, n) << '\n';
		cout << "delta (float):    " << centroidDelta(x, y, n) << '\n';

	}
}

// test with a concave configuration
void 	testKnownCentroid2(double basex, double basey, double r, uint32_t n) {
	double x[n], y[n];
	double t = 0, dt = 2 * pi / n;
	for (int i = 0; i < n; i++, t += dt) {
		x[i] = basex + r * cos(t);
		y[i] = basey + r * (sin(t) + sin(2*t));
	}	
  cout << "Testing Known Centroid at " << basex << "," << basey << " n=" << n << '\n';
	cout << "centroid (double): " << centroid(x, y, n) << '\n';
	cout << "delta (double):    " << centroidDelta(x, y, n) << '\n';

	{
		float x[n], y[n];
		double t = 0, dt = 2 * pi / n;
		for (int i = 0; i < n; i++, t += dt) {
			x[i] = basex + r * cos(t);
			y[i] = basey + r * (sin(t) + sin(2*t));
		}
		cout << "centroid (float): " << centroid(x, y, n) << '\n';
		cout << "delta (float):    " << centroidDelta(x, y, n) << '\n';
		cout << "delta_b (float):    " << centroidDelta_b(x, y, n) << '\n';

	}
}

void testAreas(const double x[], const double y[], uint32_t n) {
	float xf[n], yf[n];
	for (int i = 0; i < n; i++) {
		xf[i] = x[i];
		yf[i] = y[i];
	}
  cout << "area (double):  " <<   area(x, y, n) << '\n';
	cout << "area (float):   " <<   area(xf, yf, n) << '\n';
  cout << "areab (double): " <<   area_b(x, y, n) << '\n';
	cout << "areab (float):  " <<   area_b(xf, yf, n) << '\n';
  cout << "areac (double): " <<   area_c(x, y, n) << '\n';
	cout << "areac (float):  " <<   area_c(xf, yf, n) << '\n';
}

int main() {
	double x[] = {
		-160.55047704799998, -160.55282901199996,
		-160.55383501499998, -160.55402705599997,
		-160.55362208099996, -160.55394198299996,
		-160.55384403999997, -160.55477483099997,
		-160.55263396199996, -160.55084307999996,
		-160.55016399899998, -160.54941906599998,
		-160.54919493399998, -160.54953104799998,
		-160.55019692499997, -160.54969701599998,
		-160.54846905399998, -160.54908796599997
	};
	double y[] = {
		21.653648969, 21.653610026, 21.655347925, 21.657849979, 21.659541079,
		21.661079918, 21.662921944, 21.664474153, 21.665828973, 21.665999620,
		21.665842009, 21.664722019, 21.662664050, 21.661109000, 21.659523029,
		21.657568017, 21.655351936, 21.654088040
	};
	uint32_t n = sizeof(x)/sizeof(double);
	testExampleIsland(x, y, n);
	testKnownCentroid(-160.0, 21.0, 3.0, 100);
	testKnownCentroid(-170.0, 71.125, 3.0, 100);
	testKnownCentroid(30.0, 29.125, 3.0, 1000);
	testKnownCentroid(30.0, 29.125, 1.0, 1000);
	testKnownCentroid(30.0, 29.125, .01, 1000);
	testKnownCentroid2(30.0, 29.125, .005, 100);
	testAreas(x, y, n);
	
 	return 0;
}


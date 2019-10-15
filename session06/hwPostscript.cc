#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream f("test.ps");
	Rect r1(100.0, 150.0, 200.0, 50);
	Circle c1(300,200,50.0);
	Line L1(400,500, 600,550);
	r1.draw(f); // 100 150 moveto 300 150 lineto 300 200 lineto 100 200 lineto closepath stroke

	c1.draw(f); // 300 200 50 0 360 arc stroke
	const float r = 0.5, g = 1.0, b = 0;
	setrgb(f, r,g,b);
	c1.fill(f); // 300 200 50 0 360 arc fill
	L1.draw(f); // 400 500 moveto 600 550 lineto stroke
}
	
	
	

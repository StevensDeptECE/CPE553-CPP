#include <iostream>
using namespace std;
int main() {
	Rect r1(100, 50, 20, 40);	// Rect(x,y, width, height)
	cout << r1.area() << '\n';
  Circle c1(400, 300, 50); // Circle(x,y,radius)
  cout << c1.area() << '\n'; // area should be pi * radius squared
  Line L1(0,0, 300, 400);
  cout << L1.area() << '\n'; // area should be 0
}



	

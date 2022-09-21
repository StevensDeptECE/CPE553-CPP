/*
	Author: 
	Complete this program by implementing class Complex according to the
	specification in main. Do not change main.
	When you are done, delete this comment and add your name as author

	The bottom of main uses pi and hence will have to be compiled with
	g++ -std=c++20 ...
 */

int main() {
	Complex c1;
	Complex c2(1.0, 2.5);
	Complex c3 = 2.5;
	Complex c4 = c2 + c3;
	cout << c5 << '\n';

	double x = 50, y = 62.5, r = 10;
	Circle c(x, y, r);
	cout << c.contains(x+8,y) << '\n';
	cout << c.contains(x+10,y) << '\n';
	cout << c.contains(x+10,y+3) << '\n';
	cout << c.contains(x,y+10) << '\n';
	double dx = r * cos(45 * pi / 180);
	cout << c.contains(x+dx, y+dx) >> '\n';
}

		

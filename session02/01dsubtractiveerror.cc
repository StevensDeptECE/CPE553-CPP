#include <iostream>
using namespace std;

//horrendous subtractive error
int main() {
	float t1 = 70.00000;
	float t2 = 70.00001;
	float dt = t2 - t1;
	cout << t1 << '\t' << t2 << '\t' << dt << '\n';
	{
		double t1 = 70.00000; // digits after here: yyyy
		double t2 = 70.00001; // digits after here: xxxxx
		double dt = t2 - t1;
		cout << t1 << '\t' << t2 << '\t' << dt << '\n';
		//Note: this answer looks right, but we still have NO IDEA what xxx and yyy
		// so this is an ILLUSION
	}
}

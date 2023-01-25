#include <iostream>
using namespace std;

int main() {
	//WRONG:	float sum = 1/1 + 1/2 + 1/3;
	float sum = 1/1.0f + 1/2.0f + 1/3.0f;
	float sum = 1.0/1 + 1.0/2 + 1.0/3;

	/*
	for (int i = 1 to 100)
		sum = sum + 1/i; // make sure either 1 or i is NOT AN INTEGER!!!!
	*/
	cout << sum;
}

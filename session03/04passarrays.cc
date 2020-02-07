#include <iostream>
#include <random>
#include <time.h>
using namespace std;

default_random_engine gen(time(nullptr)); // remove seed once you are done testing...

void fillRandom(int a[], int n) {
	uniform_int_distribution<int> distribution(1,n);	
	for (int i = 0; i < n; i++)
		a[i] = distribution(gen); 
}

void print(int x[], int n) {
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';
	cout << '\n';
}

double mean(const int x[], int n) {
	double s = 0;
	for (int i = 0; i < n; i++)
		s += x[i];
	return s / n;
}

int main() {
	const int SIZE = 10;
	int x[SIZE];

	fillRandom(x, SIZE); // fill array x with SIZE random numbers
	print(x, SIZE); // print out the array
	cout << mean(x, SIZE) << '\n';
}

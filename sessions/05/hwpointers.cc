#include <iostream>
using namespace std;

// fill the array x with zeros (using pointer)
void fill(int x[], int size) {
	//x[i] = 0; // NO, use pointer!!! *p++ = 0
}

// add 1 to every element of x
void increment(int x[], int size) {
}

// double every element of x
void doubleMe(int x[], int size) {
}

// print out every element of x separated by spaces  then newline
void print(const int x[], int size) {

}

int main() {
	int x[10] = {1};
	const int size = sizeof(x)/sizeof(int);
	print(x, size);
	fill(x, size);
	print(x, size);
	increment(x, size);
	print(x, size);
	doubleMe(x, size);
	print(x, size);
}

	

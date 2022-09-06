#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

// define an n x n image, where each pixel is a 32 bit number
const int n = 512;
uint32_t img[n][n] = {0}; // set all elements to zero

/*
	the sharper the focus of an image, the greater the differences between
	adjacent pixels.  Calculate the sum of the differences for all adjacent pixels
	and the higher the number, the higher the focus
*/
uint32_t autofocus(const uint32_t img[n][n]) {
	uint32_t sum = 0;
	for (uint32_t y = 0; y < n; y++)
		for (uint32_t x = 0; x < n; x++)
			sum += abs(img[y][x+1] - img[y][x]) + abs(img[y+1][x] - img[y][x]);
	return sum;
}

int main() {
	cout << autofocus(img) << '\n'; // should be zero
}

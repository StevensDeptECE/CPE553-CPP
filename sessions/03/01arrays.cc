#include <iostream>
using namespace std;
void f() {
  int c; // scope of function f has nothing to do with main
}

uint32_t x; // this variable is GLOBAL. visible anywhere in the program
// global variables are loaded when the program loads
// lifetime is the WHOLE PROGRAM
// initialized to ZERO

// STILL GOOD STYLE TO SET YOURSELF
uint32_t y = 0; // BETTER STYLE
float z; // initialized when program loads 0.0

int main() {
	uint32_t a = 3;
	float b = 1.5f;
	double c = 2.5;
	//scope = where symbol is visible
	//lifetime = when is it born? when does it die
	uint32_t d[5]; // d[0], d[1], ... d[4] // random garbage
	uint32_t e[3] = {1, 2, 3}; // e[0] = 1, e[1] = 2, e[2] = 3

	uint32_t f[100] = {13}; // f[0] = 13, f[1] = 0, ... f[99] = 0;
	uint32_t g[100000] = {0}; // set it all to zero
	//	memset((char*)g, 3, sizeof(g));

	double m[3][2] = {
		{5, 4},
		{3, 9},
		{1, 16}
	};
	double m2[3][2] = { // all uninitialized cells are zero
		{5},
		{3, 9}
	};
	// meanwhile, somewhere in memory.... stored in ROW MAJOR order
	// ----> 5   0   3   9   0   0
	// it's always faster to go sequentially through memory
	// look up DDR ram on wikipedia

  	

}

#include <iostream>

                                    // pass by reference
void rect2polar(double x, double y, double& r, double& theta) {
  r = ...;
	theta = ....;
}

void doubleit(int a[], int len) {
  for (uint32_t i = 0; i < len; i++)
		a[i] *= 2;
}

int main() {
	double x = 3, y = 4;

	double r, theta;

	rect2polar(x,y, r, theta);

	int a[] = {1, 2, 3, 4, 5};
	doubleit(a, 5);
	
}

#include <iostream>
using namespace std;

void copy(int* src, int srcpos, int* dest, int destpos, int size) {
  dest = dest + destpos + size - 1;
	src = src + srcpos + size - 1;
	for (int i = size; i > 0; i--)
		*dest-- = *src--;
#if 0
	destpos += size;
	for (int i = srcpos + size - 1; i >= srcpos; i--)
		dest[destpos--] = src[i]
#endif
			// doesn't work
			//  for (int i = srcpos; i < srcpos + size; i++)
			//dest[destpos++] = src[i];

			
}


int main() {
	const int a[10] = {3};
	int b[10];
	copy(a, b); // copy all elements of a to b using pointers

	int c[10] = {3, 4, 5, 6};


	// c = {3,4,5,6,0,0,0,0,0,0}
	// c = {3,4 3,4,5,6,0,0,0,0}

	// wrong:
	// c = {3,4,3,4,3,4,0,0,0,0}
	copy(c, 0, c, 2, 8); // do this using pointers
	// memcpy does what we want copy to do
  // but the parameters are backwards
	// and the size is in bytes
	//memcpy(c+2, c+0, 8 * sizeof(int))
	double a[3] = {2.0, 3.0, 4.0};
	double b[3] = {2.0, -2.0, 1.0};
	double c[3];
	dot(c, a, b); // using pointers, make c = [2*2,3*-2,4*1]
}

	

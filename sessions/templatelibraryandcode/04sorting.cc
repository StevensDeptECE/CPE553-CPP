#include <iostream>
using namespace std;
// ascending order
//  5 4 3 2 1  -->  1 2 3 4 5


/*
other methods of swapping integers without a temp
using inverse operations

			x[i] = x[i] + x[i+1];
			x[i+1] = x[i] - x[i+1];
			x[i] = x[i] - x[i+1];

			x[i] = x[i] ^ x[i+1];
			x[i+1] = x[i] ^ x[i+1];
			x[i] = x[i] ^ x[i+1];
*/

//  4  3  2   1   5
template<typename T>
void sort(T x[], int n) {
	for (int j = 0; j < n-1; j++)
		for (int i = 0; i < n-1-j; i++)
			if (x[i] > x[i+1]) {
				T temp = x[i];
				x[i] = x[i+1];
				x[i+1] = temp;		
			}
}


template<typename T>
void  print(const T a[], size_t size) { // _Z5printKP...
	for (uint32_t i = 0; i < size; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

int main() {
	int x[] = {5, 4, 3, 2, 1};
	float y[] = {5.5, 4.2, 3.9, 2, 1};

	sort(x, sizeof(x)/sizeof(int));
	print(x,sizeof(x)/sizeof(int));

	sort(y, sizeof(y)/sizeof(float));
	print(y,sizeof(y)/sizeof(float));
}

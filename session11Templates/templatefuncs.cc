#include <iostream>
#include <string>
using namespace std;

//5 4 2 9
//4 2 5 9
// 5 4 3 2
// 4 3 2 5

template<typename T>
void sort(T x[], int n) {
	for (int j = 0; j < n-1; j++) {
		for (int i = 0; i < n-1; i++)
			if (x[i] > x[i+1]) {
				T temp = x[i];
				x[i] = x[i+1];
				x[i+1] = temp;
			}
	}
}
int main() {
	int a[] = { 5, 4, 2, 9};
	double b[] = {2.4, 1.2, 21.5, -9.2, 5.5};
	string c[] = {"hello", "bye", "ugh", "AAPL"};
	
	sort(a, sizeof(a)/sizeof(int));
  for (auto i : a)
		cout << i << ' ';
	cout << '\n';
	sort(b, sizeof(b)/sizeof(double));
  for (auto i : b)
		cout << i << ' ';
	cout << '\n';
	sort(c, sizeof(c)/sizeof(string));
  for (auto i : c)
		cout << i << ' ';
	cout << '\n';
}

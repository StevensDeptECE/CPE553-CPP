#include <iostream>
using namespace std;

int sum(int a, int b) {
  int s = 0;
	for (int i = a; i <= b; i++)
		s += i;
	return s;
}

int main() {
	cout << sum(5, 9) << '\n';
	for (int i = 1; i < 10; i *= 3)
		cout << i << ' ';                   // 1 3 9
	cout << '\n';

	for (int i = 100; i > 10; i = (i - 4) / 3)
		cout << i << ' ';                   // 100 32 
	cout << '\n';

	for (int i = 1; i < 30; i += 2)
		if (i % 3 == 0)
			cout << i << ' ';                 //  3, 9, 15
}



	

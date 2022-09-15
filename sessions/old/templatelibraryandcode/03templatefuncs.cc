#include <iostream>
using namespace std;

template<typename T>
void  print(const T a[], size_t size) { // _Z5printKP...
	for (uint32_t i = 0; i < size; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

class Elephant {
public:
	//	Elephant() {}
	friend ostream& operator <<(ostream& s, const Elephant& e) {
		return s;
	}
};

int main() {
	const int x[] = {5, 4, 1};
	int y[] = {5, 4, 1, 1, 9, 8, 8, 16, 423, 5};
	float z[] = {2, 3, 4};
	Elephant e[] = { Elephant(), Elephant(), Elephant() };
	print(x, sizeof(x) / sizeof(x[0]));
	print(y, sizeof(y) / sizeof(y[0]));
	//	print((int*)z, sizeof(z) / sizeof(float));
	print(z, sizeof(z) / sizeof(z[0]));
	print(e, 3);
}

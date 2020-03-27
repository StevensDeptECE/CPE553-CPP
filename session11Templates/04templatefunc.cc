#include <iostream>
#include <string>
using namespace std;
#if 0
class Elephant {
private:
	string name;
	int age;
public:
	Elephant(const string& name, int age) : name(name), age(age) {}
	friend	bool operator >(const Elephant& a, const Elephant& b) {
		return false;
	}
};
#endif

template<typename T>
void sort(T* const x, uint32_t n) {
	for (int j = 0; j < n-1; j++)
		for (int i = 0; i < n-1; i++)
			if (x[i] > x[i+1]) {
				auto temp = x[i];
				x[i] = x[i+1];
				x[i+1] = temp;
			}
}

template<typename T>
void print(const T x[], uint32_t n) {
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';
	cout << '\n';
}

int main() {
	int x[] = {4, 3, 2, 1};
	const uint32_t n = sizeof(x)/sizeof(int);
	sort(x, n);
	print(x, n);
	int x2[] = {5, 4, 3, 2, 1};
	sort(x2, sizeof(x2)/sizeof(int));
	print(x, sizeof(x2)/sizeof(int));

	cout << '\n';
	float y[] = {4.2, 2.1, 3.6, 5.2, 2.8};
	sort(y, sizeof(y)/sizeof(float));
	print(y, sizeof(y)/sizeof(float));


	string z[] = {"abc", "testing", "hello", "007"};
	print(z, sizeof(z)/sizeof(string));
	sort(z, sizeof(z)/sizeof(string));
	print(z, sizeof(z)/sizeof(string));

#if 0
	Elephant e[] = {Elephant("Fred", 1), Elephant("Alice", 2)};
	sort(e, 2);
	print(e, 2);
#endif
}

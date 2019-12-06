#include <iostream>
using namespace std;

template<typename T, typename Key>
void sort(T x[], int n, Key T::*key) {
	for (int j = 0; j < n-1; j++)
		for (int i = 0; i < n-1; i++) {
			if (x[i].*key > x[i+1].*key) {
				T temp = x[i];
				x[i] = x[i+1];
				x[i+1] = temp;
			}
		}
}

template<typename T>
void print(T x[], int n) {
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';
	cout << '\n';
}

class Elephant {
public:
	int age;
	string name;
public:
	Elephant(const string& name, int age) : name(name), age(age) {}

	friend ostream& operator <<(ostream& s, const Elephant& e) {
		return s << "Elephant " << e.name << " " << e.age;
	}

	friend bool operator >(const Elephant& e1, const Elephant& e2) {
		return e1.name > e2.name;
	}
};

int main() {
	Elephant e[] = { Elephant("Fred", 3), Elephant("Jill", 19), Elephant("Alice", 23) };

  sort(e, 3, &Elephant::name);
	print(e, 3);

	sort(e, 3, &Elephant::age);
	print(e, 3);

	
}

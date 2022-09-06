#include <iostream>
#include <string>
using namespace std;

template<typename T>
void sort(T x[], int n) {
	for (int j = n-1; j > 0; j--)
		for (int i = 0; i < n-1; i++)
			if (x[i] > x[i+1])
				swap(x[i], x[i+1]);
}


template<typename T, typename Key>
void sort(T x[], int n, Key T::*key) { // key is a pointer to a field of type Key
	for (int j = n-1; j > 0; j--)
		for (int i = 0; i < n-1; i++)
			if (x[i].*key > x[i+1].*key)
				swap(x[i], x[i+1]);
}

class Elephant {
public:
	string name;
	int age;
public:
	Elephant(const string& name, int age) : name(name), age(age) {}
#if 0
	friend bool operator >(const Elephant& a, const Elephant& b) {
		return a.name > b.name;
	}
#endif
	friend ostream& operator<<(ostream& s, const Elephant& e) {
		return s << e.name << " " << e.age << ' ';
	}
};

int main() {
	int x[] = {5, 4, 3, 2, 1};
	//         4  3  2  1  5
	sort(x, 5);
	int y[] = {6, 5, 4, 3, 2, 1};
	sort(x, 6);

	float z[] = {1.5, 2.0, 4, 3, 1.7};
	sort(z, 5);

	string a[] = {"yo", "terst", "abc"};
	sort(a, 3);
	
	for (auto e : x)
		cout << e << ' ';
	cout << '\n';

	for (auto e : a)
		cout << e << ' ';
	cout << '\n';

	Elephant e[] =
		{
		 Elephant("Fred", 3), Elephant("Alice",12), Elephant("Tina", 2)
		};
	Elephant e2[] =
		{
		 {"Fred", 3}, {"Alice",12}, {"Tina", 2}
		};
	//sort(e, 3);
	sort(e, 3, &Elephant::name); // sort elephants by name
	for (auto x : e)
		cout << x << ' ';
	cout << '\n';
	sort(e, 3, &Elephant::age); // sort elephants by age
	for (auto x : e)
		cout << x << ' ';
	cout << '\n';
	cout << sizeof(Elephant) << '\n';
}

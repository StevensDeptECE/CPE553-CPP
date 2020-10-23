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
	int age;				// relative pointer     &Elephant::age
	string name;			// relative pointer 	&Elephant::name
public:
	Elephant(const string& name, int age) : name(name), age(age) {}

	friend ostream& operator <<(ostream& s, const Elephant& e) {
		return s << "Elephant " << e.name << " " << e.age;
	}
#if 0
	// now we don't need this, we sort on ANY KEY
	friend bool operator >(const Elephant& e1, const Elephant& e2) {
		return e1.name > e2.name;
	}
#endif
	//close?	static int Elephant::* byAge() { return &Elephant::age; }
	//close?  static string Elephant::* byName() { return &Elephant::name; }
};

int main() {
	Elephant e[] = { Elephant("Fred", 3), Elephant("Jill", 19), Elephant("Alice", 23) };
	//ERROR: Elephant e2[3]; //  requires the constructor Elephant()
	Elephant e3[] = {  {"Fred", 3}, {"Jill", 19}, {"Alice", 23}   };

	sort(e, 3, &Elephant::name);
	//close?	sort(e, 3, Elephant::byAge());
	print(e, 3);

	sort(e, 3, &Elephant::age);
	print(e, 3);

	
}

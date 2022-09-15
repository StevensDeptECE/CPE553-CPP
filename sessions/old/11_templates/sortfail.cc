#include <iostream>
#include <string>
using namespace std;

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

class Elephant {
private:
	int age;
	string name;
public:
	Elephant(const string& name, int age) : age(age), name(name) {}
  friend bool operator >(const Elephant& a, const Elephant& b) {
		return a.name > b.name;
	}
	friend ostream& operator <<(ostream& s, const Elephant& e) {
		return s << e.name << ' ' << e.age;
	}
};

// in order to sort Elephants you must define operator >
// because that is what our sort algorithm uses
int main() {
	Elephant e[] = {Elephant("Joe", 20), Elephant("Alice", 19), Elephant("Fred", 1)};
  sort(e, 3);
	for (auto x : e)
		cout << x << ' ';
	cout << '\n';
}

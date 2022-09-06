#include <iostream>
using namespace std;

class Person {
public:
	string firstName, lastName;
	int age;
	Person(const string& firstName, const string lastName, int age) :
		firstName(firstName), lastName(lastName), age(age) {}
	friend ostream& operator<<(ostream& s, const Person& p) {
		return s << p.firstName << ' ' << p.lastName << ' ' << p.age;
	}
};

template<typename T, typename Key>
void sort(T x[], int n, Key T::*key) {
	for (int j = 0; j < n-1; j++)
		for (int i = 0; i < n-1-j; i++)
			if (x[i].*key > x[i+1].*key) {
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
	Person p[] = { Person("Dov", "Kruger", 52),
								 Person("Marcin", "Wisniowski", 21),
								 Person("Moshe", "Kruger", 17)
	};

	sort(p, sizeof(p)/sizeof(Person), &Person::firstName);
	print(p,sizeof(p)/sizeof(Person));
	sort(p, sizeof(p)/sizeof(Person), &Person::lastName);
	print(p,sizeof(p)/sizeof(Person));
	sort(p, sizeof(p)/sizeof(Person), &Person::age);
	print(p,sizeof(p)/sizeof(Person));
}

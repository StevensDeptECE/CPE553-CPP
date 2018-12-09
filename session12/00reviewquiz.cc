
template<typename T>
void sort(T x[], int size) {
	for (int i = 0; i < size-2; i++)
		for (int j = 0; j < size-1; j++)
			if (x[j] > x[j+1])
				swap(x[j], x[j+1]);
}

class Person {
private:
	string name;
	int age;
public:
	Person(const string& name, int age) : name(name), age(age) {}
	friend bool operator >(const Person& a, const Person& b) {
		return a.name > b.name;
	}
	//	bool operator >(const Person& b) const { return name > b.name; }
};

int main() {
	int a[] = {3, 2, 1};
  int b;
	sort(a, sizeof(a) / sizeof(int));
	print(a, 3);

	string d[] = {"hello", "ciao", "hola", "ni hao"};
	sort(d, 4);
	print(d,4);

	Person p[] = { Person("Mike", 35), Person("Alex", 19), Person("Arthur", 23) };
	sort(p, 3);

	
}

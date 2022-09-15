class LinkedList {
private:

public:

};

class Elephant {
private:
	string name;
	int age;
public:
	string name;
	int age;
	Elephant(const string& name, int age) {}
};

int main() {
	LinkedList<int> a;
	a.addEnd(3);
	a.addEnd(1);
	a.addEnd(4);
	a.addEnd(1);
	a.addEnd(5);
  cout << a << '\n'; // 3 1 4 1 5
	
	LinkedList<Elephant> b;
	b.addEnd(Elephant("Bob", 1));
	b.addEnd(Elephant("Alice", 2));
	b.addEnd(Elephant("Fred", 19));
	b.addEnd(Elephant("Rose", 12));
	cout << b << '\n';
	

#include "List.hh"
#include "Elephant.hh"
using namespace std;

int main() {
	List<int> a(10);
	a.add(3);

	cout << a << '\n';

	List<float> b(20);
	b.add(2.5f);

	cout << b << '\n';

	List<Elephant> c(5);
	c.add(Elephant("James", 5));
	cout << c;
}
	

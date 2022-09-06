#include "LinkedList2.hh"
using namespace std;

int main() {
	LinkedList<int> a;
	for (int i = 0; i < 10; i++)
		a.addStart(i);
	cout << a << '\n';
	LinkedList<int> copy(a);
	LinkedList<int> c;
	c.addStart(1);
	a = c;
	cout << a << '\n';
	
	
	LinkedList<double> b;
	for (int i = 0; i < 10; i++)
		b.addStart(i+.5);
	cout << b << '\n';
}

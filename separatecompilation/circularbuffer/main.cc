#include "circularbuffer.hh"
using namespace std;
circularbuffer f() { // this calls the move constructor: copy something about to die
	circularbuffer a(128);
	a.enqueue(3);
	// p-> [3   ]
		//    h  t
	return a;
}


int main() {
	circularbuffer b(32);
	circularbuffer b2 = b;
	b2 = b; // operator=
	b.enqueue(3);
	for (int i = 0; i < 10; i++)
		b.enqueue(i); // 3 0 1 2 3 4 5 6 7 8 9

	while (!b.isEmpty()) {
		cout << b.dequeue() << ' ';
	}
}

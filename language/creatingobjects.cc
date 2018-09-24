#include <iostream>
using namespace std;

class A{
public:
	// this object has the default constructor A() {}
};

void f(A a) {

}

int main() {
	A a1; // creates A as an auto variable (on the stack)
	f( A() ); // calling the constructor creates an anonymous (unnamed) temp

	A* ap = new A(); // create on the heap

	//	you must delete  your object when done
	delete ap;

	A* ap2 = new A[100]; // create 100 objects of type A in a single block
	//call constructor 100 times (not that this one does anything)
  delete [] ap2; // if you allocate a block, you MUST call delete []
	// this calls the destructor 100 times
	// delete ap2; would call the destructor only once

	// this is wrong
	//	A ap3 = *new A();  //leaking the memory

	using handle = std::unique_ptr<A>;

	handle p = make_unique<A>();
	// p will automatically delete when done

		

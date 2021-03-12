#include <iostream>
#include <memory.h>
using namespace std;
class Cow {
public:
  Cow() { 
		cout << "Cow constructor\n";
	}
	~Cow() {
		cout << "Cow destructor\n";
	}
};

int main() {
	int n;
	cin >> n;
	int*p = new int[n];



	delete [] p;

	int* q = (int*)malloc(10*sizeof(int));
	free(q);

	
	Cow* w = new Cow; // calls Cow::Cow() once

	delete w; // calls Cow::~Cow() once

	Cow *x = new Cow[5]; // call Cow::Cow() 5 times
  //delete x;
	
	delete [] x; // calls Cow::~Cow() 5 times
	// DIE!	delete [] x; // calls Cow::~Cow() 1000 times

	int a;

	//	delete &a; // DIE!

	
}
	
	

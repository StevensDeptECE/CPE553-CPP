class Cow {

};

int main() {
	int n;
	cin >> n;
	int*p = new int[n];



	delete [] p;

	int* q = malloc(1024*sizeof(int));
	free(q);

	
	Cow* w = new Cow; // calls Cow::Cow() once

	delete w; // calls Cow::~Cow() once

	Cow *x = new Cow[1000]; // call Cow::Cow() 1000 times
  delete x;
	
	delete [] x; // calls Cow::~Cow() 1000 times
	// DIE!	delete [] x; // calls Cow::~Cow() 1000 times

	int a;

	//	delete &a; // DIE!

	
}
	
	

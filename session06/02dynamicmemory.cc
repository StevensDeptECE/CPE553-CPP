class Cow {

};

int main() {
	int n;
	cin >> n;
	int*p = new int[10000000000];
	delete [] p;

	int* q = malloc(1024*sizeof(int));
	free(q);

	int* w = new Cow; // calls Cow::Cow() once

	delete w; // calls Cow::~Cow() once

	int *x = new Cow[1000]; // call Cow::Cow() 1000 times

	delete [] x; // calls Cow::~Cow() 1000 times
	// DIE!	delete [] x; // calls Cow::~Cow() 1000 times

	int a;

	//	delete &a; // DIE!

	

	
	

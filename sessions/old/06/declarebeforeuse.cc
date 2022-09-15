void f(int x) { // function definition
	cout << x;
}

void g(int); // function prototype (declaration)
int main() {
	//	x = 5; // illegal, must be declared already
	int x;
	f(2); // declare function above here
	g(2);
}

void g(int x) {
	cout << x;
}


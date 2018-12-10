#include <iostream>
using namespace std;

void f(int x) { cout << 'f' << x << '\n'; }
void g(int x) { cout << 'g' << x << '\n'; }

int main() {
	typedef void (*FuncIntParam)(int);
	FuncIntParam vector[2] = {f, g};

	//demonstration: call every function in the list with 0, then 1, then 2
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 2; i++)
			vector[i](j);
	}
	
}

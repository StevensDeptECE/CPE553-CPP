#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	const uint32_t S = 1024*1024;
	int* a = (int*) malloc(S);
	int* b = (int*)malloc(S);
	cout << a << '\n';
	cout << b << '\n';
	int* c = (int*)realloc(a, S*16);
	cout << c << '\n';

}

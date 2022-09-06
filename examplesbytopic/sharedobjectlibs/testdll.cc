#include <dlfcn.h>
#include <iostream>
using namespace std;

typedef int* (*VoidFunc)();
int main() {
	void* psharedlib = dlopen("./sample.so", RTLD_NOW);
	cout << "psharedlib = " << psharedlib << '\n';
	VoidFunc f = (VoidFunc)dlsym(psharedlib, "getData");
	cout << "f = " << f << '\n';
	int* p = f();
	cout << "p = " << p << '\n';

}

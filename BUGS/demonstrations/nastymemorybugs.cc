#include <cstdint>

void h() {
	int *p;

	delete [] p;
}

void g() {
	uint64_t* p = new uint64_t[16*1024];

	p[-1] = 9124591951; // put bogus value just before allocated pointer. Malloc now things we have 9124591951 bytes to return
	//	p = new int[16*1024*1024];
	delete []p; // BOOM!
}

void f() {
	int* p = new int[16*1024*1024];
	g();
	p--;

	delete [] p;
	//	delete [] p;
}


int main () {
  int a[1024] = {1};
	h();
	f();
	
}

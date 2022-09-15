void f(); // function prototype
void f(int x);

void g() {
	f();
	//	f(2);  this function does not exist
}

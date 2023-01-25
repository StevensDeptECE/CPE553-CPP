int  f() {
	return 0;
}
/*
int  f(int x) {
	return 5;
}
*/
int f(double  x) {
	return x;
}

int main() {
	f(3);
	f();
	f(2.5); // --> 2.0 --> 2

}

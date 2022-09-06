int main() {
	int a = 5;
	const int& b = a;
	a = 6;
	const int c = 2;
	int& d = c;
	d = 3;
}

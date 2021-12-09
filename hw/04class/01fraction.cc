int main() {
	fraction a(1,2); // create a fraction 1/2
	fraction b(3);   // create a fraction 3/1
	fraction c;      // create a fraction 0/1
	fraction d = a + b; // create a fraction 7/2 using a friend function
	cout << d << '\n'; // print 7/2
	fraction e(1,3);
	fraction f = a * e; // create a fraction 1/2 * 1/3 = 1/6
	cout << f << '\n';
}

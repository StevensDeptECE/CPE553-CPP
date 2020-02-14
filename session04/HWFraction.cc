int main() {
	// Main() Section 1
	Fraction f1;		// 1/1, Assume num and den are 1
	const Fraction f2(1,2); // 1/2
	Fraction f3(5);         // 5/1, Given number is num, assume den is 1
	Fraction f4(1,3);       // 1/3

	// Main() Section 2
	Fraction f5 = f2.add(f4); // 1/2 + 1/3 = 5/6
	Fraction f6 = f4.sub(f3); // 5/1 - 1/2 = 9/2
	
	// Main() Section 3	
	int r = gcd(f2, f5); // greatest common denominator, 6

	// Main() Section 4	
	cout << "f1: " << print(f1) << '\n'; // print format: (1/1)
	cout << "f2: " << print(f2) << '\n';
	cout << "f3: " << print(f3) << '\n';
	cout << "f4: " << print(f4) << '\n';
	cout << "f5: " << print(f5) << '\n';
	cout << "f6: " << print(f6) << '\n';
	cout << "r: " << r << '\n';

}	

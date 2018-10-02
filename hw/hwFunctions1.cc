int main() {
	countdown(10); // print 10 9 8 7 6 5 4 3 2 1 0 blastoff!
	
	for (int i = 0; i < 10; i++) // 0! = 1, 1! = 1, 2! = 2, 3! = 6, 4! = 24, 5! = 120, 6!= 720, ...
		cout << fact(i) << ' ';
	cout << '\n';
	cout << fact(20) << '\n'; // can you handle a factorial this big?

	for (int i = 1; i <= 15; i++) // compute the fibonacci series using a loop: 1,1,2,3,5,8,13,21,34,55, ...
		cout << fibo(i) << ' ';     // this function should be define using a for loop to count from 1 to n
	cout << '\n';

	for (int i = 1; i <= 15; i++) // compute the fibonacci series using a loop: 1,1,2,3,5,8,13,21,34,55, ...
		cout << fiborecursive(i) << ' ';     // this function should be define using recursion
	cout << '\n';

	for (int i = 1; i <= 10; i++) // print the sum of square from 1 to i.  1, 1+4= 5, 1+4+9 = 14, 1+4+9+25=39, ...
		cout << sumsquares(1, i) << ' ';
	cout << '\n';

	for (int i = 1; i <= 10; i++) // print the sum of cubes from 1 to i.  1, 1+8 = 9, 1+8+27=36, ...
		cout << sumcubes(1, i) << ' ';
	cout << '\n';

	cout << hypot(3, 4) << '\n'; // compute c = length of hypotenuse: https://en.wikipedia.org/wiki/Pythagorean_theorem

	 // compute area of triangle using Heron's formula: https://en.wikipedia.org/wiki/Heron%27s_formula
	cout << areaOfTriangle(1.0,0,  3.0,4.0, 2.5, 4.5) << '\n';

	// isPrime should return true if the number is prime, false if it is composite
	for (int i = 2; i <= 20; i++) {
		cout << i << isPrime(i) ? " prime\n" : " not prime\n";
	}

	// a perfect number is one whose factors (not including itself) add up to the number
	// for example 28 =   1*28, 2*14, 4*7.  The sum 1+2+4+7+14 = 28
	for (int i = 2; i <= 10000; i++)
		if (isPerfect(i))
			cout << i << ' ';
	cout << '\n';

	cout << sumDigits(1234) << '\n'; // the sum of the digits is 1 + 2 + 3 + 4 = 10
	cout << sumDigits(98) << '\n'; // the sum of the digits is 9 + 8 = 17
	cout << sumDigits(980100012) << '\n'; // the sum of the digits is 9 + 8 + 0 + 1 + 0 + 0 + 0 + 1 + 2 = 21
	
}
	
	

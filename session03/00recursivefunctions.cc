double fact(int n) {
  double prod = 1;
	for (int i = 1; i <= n; i++)
		prod *= i;
	return prod;
}

double fact2(int n) {
	if (n <= 1 ) {
		return 1;
	}
	return n * fact2(n-1);
}
//count (5) = 1 + count(4)
//count(0) = 0
int count(int n ) {

}


/*
	fact2(2) = 2 * fact2(1)
	fact2(1) = 1 * fact2(0)
	fact2(0) = 0 * fact2(-1) ...
*/


/*
	fibonacci series   1 1 2 3 5 8 13 21 ...

*/
int fibo(int n) {
	int a = 1, b = 1, c;
	for (int i = 0; i < n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}


int fibo2(int n) {
  if (n <= 2)
		return 1;
	return fibo2(n-1) + fibo2(n-2);
}

// future look: uses arrays
int fibo3(int n) {
	static int memo[100] = {0};
  if (n <= 2)
		return 1;
  if (memo[n] != 0)
		return memo[n];
	return memo[n] = fibo2(n-1) + fibo2(n-2);
}

/*
   f(x,y) = f(x-2,y) + f(y, x-2)

 */










 

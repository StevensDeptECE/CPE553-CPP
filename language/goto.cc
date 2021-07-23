bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int countPrimes(int n) {
	int count = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= sqrt(i); j++)
			if (i % j == 0)
				goto notPrime; // break out of the inner loop
		count++;
	notPrime:
		;
	}
}

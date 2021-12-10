int main() {
	// this loop should print the numbers from 1 to 10
	for (int i = 0; i < 10; i++)
		cout << i << ' ';
	cout << '\n';

	// this loop should count down from 10 to 0 printing each number
	for (uint32_t i = 10; i >= 0; i--)
		cout << i << ' ';
	cout << '\n';

  // this loop should print the odd numbers from 1 to 11
	for (int i = 1; i <= 11; i++)
		if (i % 2 == 0)
			cout << i << ' ';
 	cout << '\n';
}

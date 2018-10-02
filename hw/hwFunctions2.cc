int main() {
	const int n = 52, r = 6;
	cout << choose(n, r) << '\n'; // number of different games in the NJ lottery: pick 6 numbers from 52

	//practice with nested loops

	pascal(3);

	/* print out Pascal's triangle up to level n: https://en.wikipedia.org/wiki/Pascal%27s_triangle
		 it is acceptable to print asymmetrically.  For example, pascal(3) should result in:
		 1
		 1  1
		 1  2  1

pascal(4)

		 1
		 1  1
		 1  2  1
		 1  3  3  1
	*/

  // compute the sum: 1**1 + 2**2 + 3**3 + 4**4 + ... n**n where ** is expentiation
	cout << sumNtoN(3) << '\n'; // 1 + 4 + 27 = 32
	cout << sumNtoN(4) << '\n'; // 1 + 4 + 27 + 256 = 288


}

	
	

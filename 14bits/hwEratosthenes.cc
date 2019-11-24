/*
 Eratosthenes' sieve

 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21...
 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

  faster given bit implementation to just write bits[i] = 0xFFFFFFFFFFFFFFFFULL
  bits[i] = ~0ULL

	end = sqrt(n)

  for each i =  2 to end
     if the number is prime
		    clear all multiples of i (4, 6, 8, 10, 12 ,... all false)

better:
  start count = 1 (special case, 2 is prime)
  for each i =  3 to end step 2 (do only odd numbers)
    if i is prime
      for j = i*i to n step 2*i

  3x5x7 =105   64 = 2**6
lcm(105, 64) = 105*64
    64 65 66 67 68 69 70
    1  0  0  1  1   0 1   111111111111111111111111111111111111111111111111111
  
*/

class PrimeSolver {
	// new uint64_t[(n + 63) / 64]
	//copy constructor, operator = not required
public:
};

int main() {
	PrimeSolver p(63); // allocate the right number of 64-bit words
	PrimeSolver p2 = p; // this should give an error
	cout << p.countPrimes();
}

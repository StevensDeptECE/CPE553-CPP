class BigInt {
private:
	uint32_t num[4];
public:
	BigInt(uint32_t n) {
		num[0] = 0;
		num[1] = 0;
		num[2] = 0;
		num[3] = n;
	}
	friend ostream& operator <<(ostream&s, const BigInt& b) {
		// compute num % 1000000000  ---> compute the low part using ordinary 32-bit printing
		// divide by 1000000000

		//  / 100   (num*655) >> 16
		
		print(num[0], DIVISOR); // / 1000000000 *1000000000 *1000000000
		print(num[1], DIVISOR);
		print(num[2], DIVISOR)
	}
};

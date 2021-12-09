class Fraction {
private:
	const int num, den;
public:
	Fraction(int n = 0, int d = 1) : num(n), den(d) {	}
#if 0
	//the above is preferred
	Fraction(int num, int den) {
		this->num = num;
		this->den = den;
	}
#endif
};

class Complex {
private:

public:
};

int main() {
	Fraction f1(1,2); // 1/2
	Fraction f2(3);   // 3/1
	Fraction f3 = f1 + f2;
	//	Fraction f4(); // not an object
	Fraction f4; // here f4 is an object that calls Fraction()

	Complex c1(1.0, 2.5); // 1 + 2.5i
	Complex c2(2.5, 3.1);
	Complex c3 = c1 + c2;

}

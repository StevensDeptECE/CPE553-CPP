template<typename Precision>
class Complex {
private:
	Precision real, imag;

};

int main() {
	Complex<double> a(1.0, 2.5);
	Complex<float> b(1.5f, 2.5f);
	Complex<long double> c(1.5L, 2.5000000000000000000000000001L);
}

	

/*

HW Complex: complete the following main

*/

int main() {
    Complex<double> a(1.2, 5.2);
    Complex<double> b(2.1, -1.3);
    Complex<double> c = a + b;  // friend
    Complex<double> d = a - b; // member
    Complex<double> e = - b; // member

    cout << a << " " << b << " " << c << " " << d << " "  << e << '\n';
}
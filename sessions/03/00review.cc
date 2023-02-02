#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// function prototype
int f(int x);


// normal parameters are pass-by-value (make a copy)
int f(int x) {
    int y = x*x;
    x = 99;
    return y;
}

// f(x) = x ** 2  pow(x,2)
// ax^3 + bx^2 + cx + d
double eval1(double a, double b, double c, double d, double x) {
    return a*x*x*x + b*x*x + c * x + d;
}

double eval2(double a, double b, double c, double d, double x) {
    return a*pow(x,3) + b*pow(x,2) + c * pow(x,1) + d * pow(x,0);
}

double horners(double a, double b, double c, double d, double x) {
    return ((a*x + b)*x + c)* x + d;
}

/*

    //my code goes here
    void f(int x) {}
    comments don't nest!

*/

int main() {
    int a = 3;
    int z = f(a);
    cout << z << '\n';
    cout << a << '\n';
    cout << fixed << setprecision(16);
    double x = 2.1;
    cout << eval1(2.0, 3.0, -2.0, 1.0, x) << '\n';
    cout << eval2(2.0, 3.0, -2.0, 1.0, x) << '\n';
    cout << horners(2.0, 3.0, -2.0, 1.0, x) << '\n';


}
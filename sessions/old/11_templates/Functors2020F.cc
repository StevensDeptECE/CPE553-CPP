#include <iostream>
#include <cmath>
using namespace std;

int f(int x) {
    return x*x;
}

double g(double x) {
    return x*x;
}

string test(int v) {
    return "abc";
}

double (*funcOneVar) (double x);

typedef double (*FuncOneVar) (double x); // defines a type

double trap(FuncOneVar f, double a, double b, double eps) {
    double avgHeight = (f(a) + f(b)) *.5;
    double h = b-a;
    return avgHeight * h;
}


int main() {
    funcOneVar = g;
    cout << funcOneVar(3.0) << '\n';

    funcOneVar = sqrt;
    cout << funcOneVar(3.0) << '\n';
    constexpr double PI2 = 3.14159265358979 * 2;
    double z = trap(sin, 0, PI2, 0.000001);
    cout << z << '\n';

    
}
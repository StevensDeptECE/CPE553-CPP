#include <iostream>
#include <cmath>
using namespace std;

double hypot(double x, double y) {
    return sqrt(x*x+y*y);
}

double ang(double x, double y) {
    return atan2(y,x);
}

void rect2polar(double x, double y, double& r, double& theta) {
    r = sqrt(x*x+y*y);
    theta = atan2(y,x);
}


int main() {
    double x = 3.0, y = 4.0;

    double r = hypot(x,y);
    double a = ang(x,y);
     cout << "r=" << r << " a=" << a << '\n';

     double r2, a2;
     rect2polar(x,y, r2, a2);
     cout << "r2=" << r2 << " a2=" << a2 << '\n';
}
#include <iostream>
#include <iomanip>
#include <cmath>
#include <numbers>
using namespace std;
// 0.. 2    8/3
double f(double x) { return x*x; }


typedef double (*FuncOneVar)(double x);
// FuncOneVar is a pointer to functions which take one double parameter
//and return one double

double integrate(FuncOneVar f, double a, double b, int n, double eps) {
    double sum = (f(a) + f(b))/ 2;
    double h = (b-a)/ n;
    double x = a + h;
    for (int i = 1; i <= n; i++, x += h)
      sum += f(x);
    return sum * h;
}

template<typename Func>
double integrate2(Func f, double a, double b, int n, double eps) {
    double sum = (f(a) + f(b))/ 2;
    double h = (b-a)/ n;
    double x = a + h;
    for (int i = 1; i <= n; i++, x += h)
      sum += f(x);
    return sum * h;
}


class Square {
public:
    Square(){}
   inline double operator ()(double x) { return x* x; }
};

class Cube {
public:
   double operator ()(double x) { return x* x*x; }
};



int main() {
    cout << setprecision(8);
    cout << integrate(f, 0, 2, 4, .0001) << '\n';
    cout << integrate(f, 0, 2, 8, .0001) << '\n';
    cout << integrate(f, 0, 2, 16, .0001) << '\n';
    cout << integrate(f, 0, 2, 1024, .0001) << '\n';
    cout << integrate(sin, 0, numbers::pi/2, 8, .0001) << '\n';

   cout << integrate2(Square(), 0, 2, 4, .0001) << '\n';

   cout << integrate2(Cube(), 0, 2, 4, .0001) << '\n';


}
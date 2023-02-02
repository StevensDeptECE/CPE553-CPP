#include <iostream>
#include <cmath>

using namespace std;
double root1(double a, double b, double c) {
  // precedence
  // - unary negation
  // * / % multiplicative
  // + - addition
  return (-b + sqrt(b*b - 4*a*c)) / (2 * a);
}

double root2(double a, double b, double c) {
  return (-b - sqrt(b*b - 4*a*c)) / (2 * a);
}

struct Pair {
  double x1,x2;
};
Pair quad1(double a, double b, double c) {
  Pair ans;
  ans.x1 = (-b + sqrt(b*b - 4*a*c)) / (2 * a);
  ans.x2 = (-b - sqrt(b*b - 4*a*c)) / (2 * a);;
  return ans;
}

const double c1 = 1.7, c2 = 2.5, c3 = 9.2;
double g(double x) {
//  return c1 * x * c2 / c3;
  return (c1*c2/c3) * x;
}


Pair quad2(double a, double b, double c) {
  double den = 0.5 / a;
  double center = -b*den;
  double disc = sqrt(b*b - 4*a*c) * den;
  Pair ans;
  ans.x1 = center + disc;
  ans.x2 = center - disc;
  return ans;
}

// pass by reference
void quad3(double a, double b, double c, double& x1, double& x2) {
  x1 = (-b + sqrt(b*b - 4*a*c)) / (2 * a);
  x2 = (-b + sqrt(b*b - 4*a*c)) / (2 * a);
}

int main() {
  double a = 1.0, b = 2.000001, c = 1.0; //x^2 + 2x + 1 (x+1)(x+1)
  Pair p1 = quad1(a, b, c);
  cout << p1.x1 << "," << p1.x2 << '\n';

  Pair p2 = quad2(a, b, c);
  cout << p2.x1 << "," << p2.x2 << '\n';
 
  double s,t;
  quad3(a, b, c, s, t);
  cout << s << "," << t << '\n';
  double w; // w is an lvalue
  w = 5.5;
//  quad3(a, b, c, 5, 6);



}
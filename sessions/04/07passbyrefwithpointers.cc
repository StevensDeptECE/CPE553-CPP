#include <cmath>

void rect2polar(double x, double y, double& r, double& theta) {
    r = sqrt(x*x+y*y);
    theta = atan2(y,x);
}

void rect2polar(double x, double y, double* r, double* theta) {
    *r = sqrt(x*x+y*y);
    *theta = atan2(y,x);
}

int main() {
  double x = 3, y = 4;
  double r = 9, theta = 2;

  rect2polar(x, y, r, theta);
  rect2polar(x, y, &r, &theta);

}
#include <iostream>
using namespace std;

//don't ignore the warnings! This program crashes at runtime.  What is wrong?
int f(int* x) {
        x = x + 1;
	return (int)(unsigned long long)x;
}

double g(double& x) {
        x = x + 1;
  return x;
}

void double_me(double& x) {
  int& y = (int&)x;
  y *= 2;
}

void double_me2(double* x) {
  *((uint64_t*)x) *= 2;
}

int main() {
  int a = 3;
  cout << f(&a) << '\n';
  
  double pi = 3.14159;
  cout << g(pi) << '\n';
  double_me(pi);
  cout << pi << '\n';
  double_me2(&pi);
  cout << pi << '\n';
  return 0;
}

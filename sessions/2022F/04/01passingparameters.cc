// pass root1 and root2 by reference
void quadratic(double a, double b, double c, double& root1, double& root2) {
  double disc = sqrt(b*b-4*a*c);
  double temp = 1 / (2*a)
  root1 = (-b + disc) * temp;
  root2 = (-b - disc) * temp;
}


int main() {
  double x;
  cin >> x;
  double y = 2.0 * x / 3.0; // (2.0/3.0) * x;  
  quadratic(1.0, 2.0001, 1, root1, root2);
  cout << root1 << "," << root2 << '\n';

  double v = factorial(-1); // recursive
}
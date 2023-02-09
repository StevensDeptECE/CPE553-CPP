
int main() {
  const Complex a(1.5, 2.1); // (1.5,2.1)  1.5 + 2.1i
  const Complex b(1.6, -1.4);
  const Complex c  = a + b; // (3.1, 0.7)
  const Complex d = a - b; // (-.1, 3.5)
  const Complex e = a * b;
  const Complex f = a.add(b); // use a member function
  const Complex g = a.neg(); // -a
  const Complex h = -a; // operator -()
  cout << c << '\n';
  cout << d << '\n';
  cout << e << '\n';
  cout << f << '\n';
  cout << g << '\n';
  cout << h << '\n';

}
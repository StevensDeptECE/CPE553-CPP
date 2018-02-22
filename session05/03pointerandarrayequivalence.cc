int main() {
  int x[10];
  x[0] = 5;
  int* const p = x; // p and x are the same (const pointers to int)
  cout << x[0] << p[0] << '\n';

  const int y[10] = {3};
  const int* const q = y; // q and y are the same
  cout << y[0] <<'\n';
  /// illegal, y[] is const  y[0] = 55;
  //  *q = 55;

  // what is the difference between x and y?
  // what is the difference between p and q?
}

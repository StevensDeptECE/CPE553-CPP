int main() {
  int a, b,c;
  cin >> a >> b >> c;

// bad style, too many side effects in the same expression
  int d = (a++ * (b--) * (c+3)) / (c++ - a);

  int x[10], y[10], z[10];


// standard c++ idiom
  z[i++] = y[j++];

  z[i] = y[j];
  i++;
  j++;

  

}
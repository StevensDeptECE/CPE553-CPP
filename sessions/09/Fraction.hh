#include <iostream>

class Fraction {
private:
  int num, den;
public:
  Fraction(int n, int d);
  Fraction operator +(const Fraction& b) const;
  friend std::ostream& operator <<(std::ostream& s, const Fraction& f);
};

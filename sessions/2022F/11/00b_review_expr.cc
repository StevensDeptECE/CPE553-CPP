/*
 x + 0  --> x
 x * 1  --> x
x - x  --> 0
*/


class expr {
public:
  virtual double eval() const = 0; // pure virtual
  virtual const expr* simplify() const = 0; // pure virtual
};

class add : public expr {
private:
    const expr* a;
    const expr* b;
public:
  add(const expr* a, const expr* b) : a(a), b(b) {}
  double eval() const override { return a->eval() + b->eval(); }
#if 0
  const expr* simplify() const { 
    if (a isa constant and b isa constant ) {
      return new constant(a->eval() + b->eval()); 
    }
#endif    
    
    return this; }
  
};

class mul : public expr {
private:
    const expr* a;
    const expr* b;
public:
  mul(const expr* a, const expr* b) : a(a), b(b) {}
  double eval() const override { return a->eval() * b->eval(); }
};

class constant : public expr {
private:
    double v;
public:
  constant(double v) : v(v) {}


  double eval() const override { return v; }
  const expr* simplify() const { return this; }
 
};


int main() {
    const expr* e = new constant(5.0);
    double z = e->eval();
    cout << z << '\n'; // 5

    const expr* e2 = new add(e, new constant(6));
    cout << e2->eval() << '\n'; // 5

    const expr* e2 = new add(e, new constant(6));

    const expr* e3 = new mul(new add(new constant(2), new constant(3)), new add(new constant(1), new constant(4)));
    cout << e3->eval();

    expr* s = e3->simplify();
    cout << s->eval() << '\n';
}
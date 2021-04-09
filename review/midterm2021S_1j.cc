struct A {
	virtual void f() {}
};

struct B : public A {
	virtual void g() {}
};

void f() {
	B b1;
	A a1;
	A* p = &b1;
	p->f();
	  p->g(); //the parent does not know about g
}

class Airplane {
public:
	void fly() {}
};

class FighterPlane : public Airplane {
public:
	void shoot() {}
};

class CropDuster : public Airplane {
public:
	void pesticide() {}
};

int main() {
	Airplane a;
	a.shoot(); // NO!

	FighterPlane fp;
	fp.fly();
	fp.shoot();

	Airplane*p = &a;
	p->fly();
	p = &fp;
	p->fly();

	CropDuster cd;
	cd.fly();
	cd.pesticide();
	// NOT:	cd.shoot();
}

class Matrix {
private:
	int rows, cols;
	double* m;
public:
	double get(int r, int c) const {
		return m[r*rows + c];
	}
};



class Shape {
private:
	int* thingy;
public:
	Shape() { thingy = new int[5]; }
	virtual void draw() const = 0;
  virtual ~Shape() { delete[] thingy; }
};

class Sphere : public Shape {
private:
	double* p;
public:
	Sphere(double r) : r(r) {
		p = new double[1000];
	}
	~Sphere() {
		delete [] p;
	}
	void draw() const {

	}
};


int main() {
	vector<Shape*> shapes;
	for (auto s : shapes) {
		s->draw();
	}
	// give back all the memory

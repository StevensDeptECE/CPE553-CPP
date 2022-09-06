class Surface3d {
public:
	virtual double f(double u, double v) = 0;
	virtual ~Surface3d(){}
};

class Sphere : public Surface3d {

public:
	double f(double u, double v)  {

	}

};

class Parabaloid : public Surface3d {
public:
	double f(double u, double v) {

	}
};

class Drawing {
private:
	vector<Surface3d*> shapes;
public:
	Drawing() {
		shapes.push_back(new Paraboloid());
		shapes.push_back(new Paraboloid());
		shapes.push_back(new Sphere());
	}
	void draw() {
		for (auto s : shapes)
			s -> draw();
	}
	~Drawing() {
		for (auto s : shapes)
			delete s;
	}

};
	
int main() {

	for (auto  s : shapes) {
		cout << *s << ' ';
	}

	for (vector<Surface3d*>::iterator i = shapes.begin(); i != shapes.end(); ++i)
		cout << *i << ' ';
}	

}






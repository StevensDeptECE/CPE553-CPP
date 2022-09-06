int main() {
	int a = 2;

	float b = a; // no cast required
	a = 2123000000;
	b = a;
	cout << b << '\n'; // lose a couple of digits, OH WELL...

	b = 0.5; // automatically converts double constant to float 0.5f
	a = b; // we are losing the 0.5

	b = (float)a; // old style cast

	b = float(a); // new C++ style

	int c = (int)1.5 + 1.3 + 1.3 ; // 3 (casting has higher precedence)
	
	int d = (int)1.2 * 2.8; // 2 (casting has HIGHER PRECEDENCE than *)
  int e = int(1.2) * 2.8; // new functional style is clearer


	Giraffe g;
	Elephent* e = (Elephant*)&g; // this is wrong
	Elephant* e = static_cast<Elephant*>&g; //equally wrong
	//e->drink(); // not an elephant, crash


	/*
		Imagine Vehicle... Car...Bus...Truck
		all have payToll() method
	*/
	
  Vehicle* v = new Car( ...);
	v->payToll();
	
	Vehicle* v2 = new Truck( ...);
	v2->payToll();
	
	Truck* t = dynamic_cast<Truck*>(v); // fails, t = nullptr
	if (t != nullptr) {
		// do what you want to the truck
	}

	t = dynamic_case<Truck*>(v2);
	if (t != nullptr) {

	}
}

class Airplane {
private:
	int fuel;
public:
	void fly() { cout << "flying"; }
	Airplane(int fuel) : fuel(fuel) {}
};

//mistakes: 1. Bird is NOT an airplane.
//2. parent constructor not default (error)
//3. food is uninitialized
class Bird : public Airplane {
	int food;
public:
	
	void eat(int f) { food += f; }
};

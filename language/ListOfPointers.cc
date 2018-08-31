#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Vehicle {
public:
	virtual void print() const = 0;
};
class Car : public Vehicle {
public:
	void print() const {
		cout << "Car";
	}
};
class Truck : public Vehicle {
public:
	void print() const {
		cout << "Truck";
	}
};
class Bus : public Vehicle {
public:
	void print() const {
		cout << "Bus";
	}
};

default_random_engine generator;
uniform_int_distribution<int> pickOne(1,3);

class TrafficSimulator {
private:
	std::vector<Vehicle*> vehicles;
public:
	TrafficSimulator(int numVehicles) {
		for (int i = 0; i < numVehicles; i++)
			switch(pickOne(generator)) {
			case 1:
				vehicles.push_back(new Car());
				break;
			case 2:
				vehicles.push_back(new Truck());			
				break;
			case 3:
				vehicles.push_back(new Bus());
				break;
			default:
				cerr << "ERROR, should be 1 to 3\n";
			}

	}
	void print() {
		for (int i = 0; i < vehicles.size(); i++)
			vehicles[i]->print();
		cout << '\n';
		
		for (auto v : vehicles)
			v->print();
		cout << '\n';

		for (vector<Vehicle*>::iterator i = vehicles.begin(); i != vehicles.end(); ++i)
			(*i)->print();
		cout << '\n';
		
		
	}

};

int main() {
	TrafficSimulator t(10);
	t.print();
}

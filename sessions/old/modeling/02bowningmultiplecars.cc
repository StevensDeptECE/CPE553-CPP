class Car {};

class Person {
private:
	vector<Car*> cars;
public:
	Person() {} // you are born without a car
	~Person() { // when you die we sell all your cars!
		// or should we bury them with you?
		for (auto c : cars)
			sell(c);
	}
	void buy(Car* c) {
		cars.push_back(c);
	}
	void sell(int which) {
		if (which >= cars.size())
			return;
		delete cars[which];
		cars[which] = cars[cars.size()-1];
	}
};

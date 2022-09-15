class Person;

class Car {
private:
	Person* owner_;
public:
	Car() : owner_(nullptr) {}
	void bought(Person* p) { owner_ = p; }
	Person*  owner() const { return owner_; }
};

class Person {
private:
	Car* owned;
public:
	Person(Car* c) : owned(c) {}
};

int main() {
	Car c1;
	Person dov(c1);
	Person ellen(c1);
	// shared  ownership of a car

	//police can ask
	cout << c1.owner() << '\n';

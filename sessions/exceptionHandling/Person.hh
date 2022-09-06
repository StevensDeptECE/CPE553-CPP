class Person {
private:
	int age;
	string firstname;
	string lastname;

public:
	Person( ...) {}

	int getAge() const throw(const char*) {
    if (age < 0)
			throw "BadVal";
	}

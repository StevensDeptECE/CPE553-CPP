#pragma once

#include <iostream>
#include <string>

class Elephant {
public:
	int age;
	std::string name;
public:
	Elephant() : name(""), age(0) {}
	Elephant(const std::string& name, int age) : name(name), age(age) {}

	friend std::ostream& operator <<(std::ostream& s, const Elephant& e) {
		return s << "Elephant " << e.name << " " << e.age;
	}

	friend bool operator >(const Elephant& e1, const Elephant& e2) {
		return e1.name > e2.name;
	}
};

#pragma once

class Person {
private:
	string name;
	static int count; // extern int Person::count;
public:
	Person(const string& name) : name(name) { count++; }
	~Person() { count--; }
	static int getCount() { return count; }
};

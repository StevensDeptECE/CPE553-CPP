#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int main() {
	std::unordered_map<std::string, std::string> test;
	test["yo"] = "ho";

	std::cout << test["yo"] << '\n';
	std::string a, b;
	a = "a", b = "b";
	test.insert(std::make_pair(a, b));
	std::cout << test["a"] << '\n';
	a = "c", b = "d";
	std::cout << test["a"] << '\n';

	std::vector<std::string> list;
	list.push_back(a);
	list.push_back("x");
	test.insert(std::make_pair(list[0], list[1]));
	std::cout << test["c"] << '\n';
	
}

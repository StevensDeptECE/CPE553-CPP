#include <cstdint>
#include <iostream>
using namespace std;
/*
	This is a part of a hashmap with a dirty secret.
	It crashes horribly! Use g++ -fsanitize=address
*/
class HorribleHashMap {
private:
  struct Node { // bogus, just for demo purposes
    uint32_t something;
    Node* next;
  };
  Node** table;
	uint32_t capacity;
public:
	HorribleHashMap(uint32_t capacity) : capacity(capacity-1) {
		table = new Node*[capacity];
		for (int i = 0; i <= capacity; i++)
			table[i] = nullptr;
	}
  uint32_t hash(uint32_t v) {
    uint32_t sum = 0x12F2B8 ^ v;
		sum ^= ((sum << 17)| (sum >> 15));
		sum ^= ((sum << 3) | (sum >> 29));
		return sum;
	}
	void add(int v) {
		table[hash(v)]++;
	}
};

int main() {
	HorribleHashMap a(1024);
	constexpr int n = 1000000;
	for (int i = 0; i < n; i++)
		a.add(i);
	return 0;
}

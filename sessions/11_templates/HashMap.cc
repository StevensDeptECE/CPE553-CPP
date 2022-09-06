#include <iostream>
using namespace std;

template<typename T>
class HashMap {
private:
	struct Node {
		string key;
		T      val;
		Node(const string& key, const T& v) : key(key), val(v) {}
	};

	uint32_t capacity;
	Node* table;
	uint32_t count;
	int hash(const char s[], uint32_t len) {
		uint32_t sum = len;
		for (int i = 0; i < len; i++)
			sum = sum ^ (sum << 13 | sum >> 19) + s[i];
		return sum & capacity;
	}
	void grow() {
		// double in size when table gets more than 1/2 full
	}
public:
	HashMap(uint32_t n) : capacity(n-1), table(new Node[n]), count(0) {  // T::T()
	}

	~HashMap() {
		delete [] table;
	}

	HashMap(const HashMap& orig) = delete ;
	HashMap& operator =(const HashMap& orig) = delete ;

	void add(const string& key, const T& val) {
		if (count*2 > capacity)
			grow();
		uint32_t pos = hash(key.c_str(), key.length());
		while (table[pos].key != "") {
			pos++;
			if (pos > capacity)
				pos = 0;
		}
		table[pos] = Node(key, val);
		count++;
	}

	const	T* get(const char key[], uint32_t len) const {
		uint32_t pos = hash(key, len);
		while (table[pos].key != "") {
			if (strcmp(table[pos].key, key) == 0) {
				return &table[pos].val;
			}
			pos++;
			if (pos > capacity)
				pos = 0;
		}
		return nullptr;
	}

};

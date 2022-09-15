#include <iostream>
#include <utility>

class BadGrowArray {
private:
	int*     data;
	uint32_t size;
public:
	BadGrowArray() : size(0), data(nullptr) {}

	~BadGrowArray() {
		delete [] data;
	}

	BadGrowArray(const BadGrowArray& orig) : size(orig.size), data(new int[orig.size] ){
		for (uint32_t i = 0; i < size; i++)
			data[i] = orig.data[i];
	}

	BadGrowArray& operator =(BadGrowArray copy) {
		size = copy.size;
		std::swap(data, copy.data);
		return *this;
	}
	
	BadGrowArray(BadGrowArray&& orig) : size(orig.size), data(orig.data) {
		orig.data = nullptr;
	}

	//data --> [3, 1, 4]
	
	void addEnd(int v) {
		const int* old = data;
		data = new int[size+1];

		for (uint32_t i = 0; i < size; i++)
			data[i] = old[i];
		data[size] = v;
		size++;
		delete [] old;
	}
	void addStart(int v) {

	}
	friend std::ostream& operator <<(std::ostream& s, const BadGrowArray& array) {
		for (uint32_t i = 0; i < array.size; i++)
			s << array.data[i] << ' ';
		return s;
	}
};


int main() {
	BadGrowArray a; // empty list
	a.addEnd(3);
	a.addEnd(1);
	a.addEnd(4); // 3 1 4
	for (int i = 0; i < 10; i++) // O(n^2)
		a.addEnd(i);
	std::cout << a << '\n';
}

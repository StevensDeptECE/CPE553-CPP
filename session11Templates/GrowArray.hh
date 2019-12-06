#pragma once

#include <iostream>

template<typename T>
class GrowArray {
private:
	uint32_t capacity; // TODO: You preallocate for speed!
	uint32_t length; // current amount used
	T* data;
	void grow() {
		T* old = data;


		//TODO: your grow should double every time   1 -->2 -->4 -->
		data = new T[length+1]; // calls T::T()
		for (int i = 0; i < length; i++)
			data[i] = old[i];
		length++;
	}
public:
	GrowArray() : length(0), data(nullptr) {}

	void addEnd(const T& v) { //TODO: make this O(1)
		grow(); // O(n)
		data[length-1] = v;
	}

	T removeEnd() {
    length--;
		return data[length];
	}

	void addStart(const T& v) {
		//TODO:!!!
	}

	void removeStart() {

	}
	const T& operator [](int i) const {
		return data[i];
	}

	T& operator [](int i) {
		return data[i];
	}

	friend std::ostream& operator <<(std::ostream& s, const GrowArray<T>& list);

	class Iterator {
	private:
		
	public:
		Iterator(GrowArray<T>& x) {
			
		}

		bool operator !() const {
			//TODO: return true if NOT done
		}


		// unary ++ (pre-increment)
		operator ++() {

		}
		T& operator *() const {

		}
#if 0
		// not used!
		// this ++ int
		operator ++(int) {

		}
#endif

	};
	
};

template<typename T>
std::ostream& operator <<(std::ostream& s, const GrowArray<T>& list) {
	for (int i = 0; i < list.length; i++)
		s << list[i] << ' ';
	return s;
}

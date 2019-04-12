class OutOfBounds {};

class List {
private:
	int* data;
	int len;
public:
	List(int n) : data(new int[n]), len(n) {}

	int operator [](uint32_t i) throw (OutOfBounds) {
		if (i >= len)
			throw OutOfBounds();
		return data[i];
	}
};

int main() {
	List list1(10);
	try {
		for (int i = 0; i < 1000; i++)
			cout << list1[i] << ' ';
	} catch (OutOfBounds e) {
	}
}

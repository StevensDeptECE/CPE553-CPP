class MyObject {
private:
	MyObject previous; // what is wrong with these definitions inside this class?
	MyObject next;
	int val;
public:
	MyObject() : val(0) {}
};

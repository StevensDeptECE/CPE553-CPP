#include <cstring>
#include <iostream>
#include <memory.h>

using namespace std;

class String {
private:
	uint32_t capacity;// DO NOT CHANGE THE ORDER!! I WILL HUNT YOU DOWN...
	uint32_t len;
	char* s;
	void checkGrow(uint32_t growBy) {
		if (capacity - len < growBy) {
			const char* old = s;
			s = new char[capacity = growBy + capacity*2];
			memcpy(s, old, len);
			delete [] old;
		}
	}
public:
	String(const char* s) : String(strlen(s), s) {}


#if 0
		: capacity(strlen(s)), len(capacity), s(new char[capacity]) {
#if 0
		int i;
		for (i = 0; s[i] != '\0'; i++)
			;
		capacity = i;
#endif
		memcpy(this->s, s, capacity);
	}
#endif
	String(uint32_t capacity, const char* s)
		: capacity(capacity), len(strlen(s)), s(new char[capacity]) {
		memcpy(this->s, s, len);
	}
	String(uint32_t capacity, char c, uint32_t copies) : String(capacity, "") {
		checkGrow(slen * copies);
    memset(this->s+len, copies, c);
	}
	~String() {
    delete [] s;
	}
	String(const String& orig)
		: capacity(orig.capacity), len(orig.len), s(new char[orig.capacity]) {
		memcpy(s, orig.s, len);
	}
	String& operator =(String copy) {
    capacity = copy.capacity;
		len = copy.capacity;
		swap(s, copy.s);
		return *this;
	}
	String(String&& orig) : capacity(orig.capacity), len(orig.len), s(orig.s) {
    orig.s = nullptr;
	}
	void append(const char* s, uint32_t copies) {
		uint32_t slen = strlen(s);
		checkGrow(slen * copies);
		char* p = this->s + len;
		for (int i = 0; i < copies; i++, p += slen) 
			memcpy(p, s, slen);
		len += slen * copies;
	}
	
	String& operator +=(const String& r) {
		checkGrow(r.len);
		memcpy(s+len, r.s, r.len);
	}
};

void f(String x) {// calls copy constructor

}

String g() { // calls move constructor
  String s("testing");
	return s;
}

int main() {
	String s("testing");
	String s2(1024, "testing");
	
	String s3(1024, 'a', 100);
  s2.append("def", 3);
	s2 += s;
  String s4 = s2; // call copy constructor
	String s5(s2); //  call copy constructor
	f(s2);

	int a = 3; // initialization
	s3 = s2; //operator=
}

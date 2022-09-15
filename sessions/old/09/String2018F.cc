#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
	uint32_t len;
	char* s;
	uint32_t stringlen(const char* str) {
		uint32_t count = 0;
		while (*str++ != '\0')
			count++;
		return count;
	}
public:
  String() : len(0), s(nullptr) {}
	String(const char str[]) : len(strlen(str) ), s(new char[len]) {
		for (int i = 0; i < len; i++)
			s[i] = str[i];
		//probably faster for large blocks: 		memcpy(s, str, len);
	}
	String(const char str[], uint32_t mult) : len(strlen(str)*mult), s(new char[len]) {
		uint32_t strsize = len / mult;
		int c = 0;
		for (int j = 0; j < mult; j++)
			for (int i = 0; i < strsize; i++, c++)
				s[c] = str[i];                  // hellohellohello....			
	}
	~String() {	delete [] s; }
	String(const String& orig) : len(orig.len), s(new char[len] ) {
		uint64_t* src = (uint64_t*)orig.s;
		uint64_t* dest = (uint64_t*)s;
		uint32_t count;
		for (count = len; count >= 8; count -= 8)
			*dest++ = *src++;
		char* pdest = (char*)dest;
		char* psrc = (char*)src;
		for ( ; count > 0; count--)
			*pdest++ = *psrc++;
	}
#if 0
	// Don't write operator = the old way, it's a maintenance nightmare!
	void operator =(const String& orig) {
		if (this != &orig) {
			delete [] s;
			len = orig.len;
			s = new char [len];
			uint64_t* src = (uint64_t*)orig.s;
			uint64_t* dest = (uint64_t*)s;
			uint32_t count;
			for (count = len; count >= 8; count -= 8)
				*dest++ = *src++;
			char* pdest = (char*)dest;
			char* psrc = (char*)src;
			for ( ; count > 0; count--)
				*pdest++ = *psrc++;
		}
	}
#endif
	String& operator =(const String& orig) {
		String copy(orig);
		len=orig.len;
		swap(s, copy.s);
		return *this;
	}
	char  operator [](const uint32_t pos)const {
		//TODO:		if (pos >= len)
		//TODO: throw Ex(__LINE__, __FILE__, OUT_OF_BOUNDS);
		return s[pos];

	}
  char& operator [](uint32_t pos) { return s[pos]; }
  friend ostream& operator<<(ostream& s, const String& str) {
    for (uint32_t i = 0; i < str.len; ++i)
			s << str[i];
		return s;
	}
};

int main() {
	String s;
	String s2 = "abc"; // a b c '\0'  control-@ (ASCII NUL)
	//s2 += "def";
	String copy(s2);
	String copy2 = s2;
	String x = "qqq";
	copy2 = copy = x; // this is why we need to return String& in operator =
  copy = copy; // for a single = it would not matter
	
	String s3("xyz", 5); // xyzxyzxyzxyzxyz
	//	String s4 = s3.substring(3, 2); // from position 3 length 2
	//	cout << s4 << '\n';
	char c  = s3[3];
	s3[4] = 'a';
	cout << s3;
	//	s3.replace('x', 'q');
	const String hello = "hello";

	//cout << hello.length() << '\n';
	//s3.insert(5, hello);
	//	String s5 = s2 + s3;
	//	cout << s5 << '\n';
	
}

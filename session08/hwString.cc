#include <iostream>
using namespace std;

class String {
private:
  int len;
	char* s;
public:
	String(const char * str) {}
	~String() {}
	String(const String& orig) {}
	String& operator =(const String& orig) {}
  String(String&&) {}
	friend ostream& operator<<(ostream& s, const String& str) {
	}
};

int main(){
	String s = "abc";
	String s2 = "hello there";
	String s3 = s + s2; // "abchello there"
	String s4 = s3; // copy constructor
	s4 = s; // s4 = "abc"
	cout << s4;
}

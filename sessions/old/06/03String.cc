class String {
private:
	char* s;
	int len;
public:
  String() : s(nullptr), len(0) {}
	String(const char str[]) {
		int count = 0;
		while (str[count] != '\0') {
			count++;
		}
		s = new char[count];
		for (int i = 0; i < count; i++)
			s[i] = str[i];
		len = count;
	}
	~String() {	delete [] s; }
	friend void operator +=(String& a, const String& b)  {
		const char* old = a.s;
		a.s = new char [a.len + b.len];
		for (int i = 0; i < a.len; i++)
			a.s[i] = old[i];
		for (int i = 0; i < b.len; i++)
			a.s[a.len + i] = b.s[i];
		a.len += b.len;
	}

	friend ostream& operator <<(ostream& s, const String& str) {
		for (int i = 0; i < str.len; i++)
			s << str.s[i];
		return s;
	}
	
};

int main() {
	String s;
	String s2("abc");
	s += s2; // s = "abc"
	s += s2; // s = "abcabc"
	cout << s << '\n';
}

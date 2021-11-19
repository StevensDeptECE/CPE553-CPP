#include <iostream>
#include <regex>

using namespace std;

const char s[] = "/*testing testing 123*/   class ABC";
const char s2[] = "class   a123";

int main() {
	regex r( "class\\s+([a-zA-Z_][a-zA-Z0-9_]*)");

	cmatch m;

	const char* p = s;
  if (regex_search (p,m,r)) {
		cout << m[0] << '\n';
		cout << m[1] << '\n';
		cout << m.position() << "\t" << m.length() << "\n";
		cout << m.position(1) << "\t" << m.length(1) << '\n';
  }
}

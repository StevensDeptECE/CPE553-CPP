#include <iostream>
#include <regex>

using namespace std;

const char s[] = R"(
void f(int x, int y) {}
uint32_t gello(int);
long double h123(long double x,) {}
)";

int main() {
	regex r( R"([a-zA-Z_][\w_]*\s*\([^\)]*\))");

	cmatch m;

	cout << "Target sequence: " << s << endl;
	//	cout << "Regular expression: " << r << endl;
	cout << "The following matches and submatches were found:" << endl;

	const char* p = s;
  while (regex_search (p,m,r)) {
		//    for (auto x : m)
		cout << m[0] << "\t" << m.length() << '\n';
		p = p + m.position() + m.length();
		cout << "P=" << p << "\n\n";
  }
}
	

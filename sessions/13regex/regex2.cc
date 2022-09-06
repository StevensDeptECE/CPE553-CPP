#include <iostream>
#include <regex>

using namespace std;

const char s[] = R"(
void f(int x, int y) {}
uint32_t gello(int);
long double h123(long double x,) {}
)";

// xxxhelloyyy


int main() {
	regex r( R"([a-zA-Z_][\w_]*\s*\([^\)]*\))");
	//  regex r(R"( xxx([a-z][a-z0-9]*)yyy )");
	cmatch m;

	cout << "Target sequence: " << s << endl;
	//	cout << "Regular expression: " << r << endl;
	cout << "The following matches and submatches were found:" << endl;

	const char* p = s;
  while (regex_search (p,m,r)) {
		//    for (auto x : m)
		cout << m[0] << "\t" << m.length() << '\n';
		for (int i = 0; i < m.size(); i++)
			//			m.position(1)  m.length(1)
			cout << m.position(i) <<  "," << m.length(i);
		p = p + m.position() + m.length();
		cout << "P=" << p << "\n\n";
  }
}
	

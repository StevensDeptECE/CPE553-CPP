#include <iostream>
#include <regex>

using namespace std;

string s = R"(
void f(int x, int y) {}
uint32_t gello(int);
long double h123(long double x,) {}
)";

int main() {
	regex r( R"([a-zA-Z_][\w_]*\s*\([^\)]*\))");

	smatch m;

	cout << "Target sequence: " << s << endl;
	//	cout << "Regular expression: " << r << endl;
	cout << "The following matches and submatches were found:" << endl;

  while (regex_search (s,m,r)) {
    for (auto x : m)
			cout << x << "\t";
    cout << endl;
    s = m.suffix().str();
  }
}
	

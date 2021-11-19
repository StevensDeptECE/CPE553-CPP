#include <iostream>
#include <string>
#include <regex>

using namespace std;

#if 0
cout << R"(
***************************************************************
*                                                             *
*   Hello there!                                              *
*   cout << \"hello\";                                        *
*                                                             *
***************************************************************
)";
#endif


//int x = 5 /* this is a comment */5;

string s = R"(
void f(int x, int y) {}\n
uint32_t gello(int);
cout << "hello";
long double h123(long double x,int y) {}
)";

int main() {
	//	regex r2("\\d{3}[\\.\\-] ");
	//  regex r3("\\\\"); // 4 \ to make one backslash 

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
	

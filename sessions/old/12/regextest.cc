#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
	string phonenum = "\\(?[0-9]{3}[\\)\\.\\-][0-9]{3}[\\.\\-][0-9]{4}";
	string word = "test";
	string searchwithin = "this is a test. testing testing 123";
	regex r(word);
	bool doesItMatch = regex_match(searchwithin, r);
	cout << "match = " << doesItMatch << '\n';
  smatch m;
																			 
  while (regex_search (searchwithin, m, r)) {
    for (auto x:m) cout << x << " ";
    cout << endl;
    searchwithin = m.suffix();
  }

	string decimal = "\\d+\\.[0-9]*";
	string target2 = "this 1.2 is 1.51251 a -124.11 test .12141";
	regex r2(decimal);
  while (regex_search (target2, m, r2)) {
    for (auto x:m) cout << x << " ";
    cout << endl;
    target2 = m.suffix();
  }

#if 0
						// regex with characters not working for us, use strings!
	const char* pointPattern = "\\((\\-?\\d*(?:\\.\\d*)?)\\,(\\-?\\d*(?:\\.\\d*)?)\\)";
	const char str[] = "this (1.2,1.5) is (1.51251,2.512) a (-124.11,41) test (.12141,1005.2283)";
						const char*p = str;
						regex r3(pointPattern);
						cmatch m2;
						while(regex_search(p, m2, r3)) {
							//							for (auto x : m2) {
								cout << m2.str(1) << " , " << m2.str(2) << '\n';
								p = str + m2.position() + m2.length();
								//							}
						}
#endif
}

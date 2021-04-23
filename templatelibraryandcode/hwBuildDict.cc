#include <iostream>
using namespace std;

/*
	1. use unordered_map (fast)
	2. strip out all punctuation, capital letters

	3. open an ifstream
	4. read in lines:

	  ifstream f(...);
		f.getline(buf, len)
		
	3. words consist of letters, numbers apostrophe ' hyphen -
	Note:  -- is NOT a hyphen
	4. open istringstream on your line
  5. add word to your dictionary

	dict[word] = count++;

 */


int main(int argc, char* argv[]) {
	int numTimes = atoi(argv[1]);
	for (int i = 2; i < argc; i++)
		cout << argv[i] << '\n';
	//	printEveryWordGreaterThan(numTimes);
}

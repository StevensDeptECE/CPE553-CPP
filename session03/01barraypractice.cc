#include <iostream>

using namespace std;

void reverse(int x[], int len) {
  for (int i = 0; i < len / 2; i++)
		swap(x[i], x[len-1-i]);
}

// write reverse2() recursively
void reverse2(int x[], int len);

void removeOdd(int x[], int len) {

}

// print out all elements in the array on one line
void print(const int x[], int len) {

}

// h e l l o '\0'   --> false
// atoyota\0
bool isPalindrome(const char s[]) {

}

// h e l l o
// h l l '\0'
void devowelize(char s[]) {
	// i go forward through the array until '\0'
	// use a different variable, start j= 0
	// every time s[j] = s[i]
	// only increment j if it is NOT a vowel
	// don't forget to add on the '\0' at the end
}



int main() {
	cout << "yo ho ho\n";
	int x[] = {1, 2, 3};

	// 1 2 4 8 16 ... 1024
	const int SIZE = 10;
	int y[SIZE]; // 9 7 -12510510 2 0 1240124501 1241 1204
	y[0] = 1;
	//ERROR size is const:	SIZE++;
	for (int i = 1; i < SIZE; i++)
		y[i] = y[i-1] * 2;

	for (int i = 0, j = 1; i < SIZE; i++, j *= 2)
		y[i] = j;

	int c[10] = {6, 1, 2, 3, 5};
	for (int i = 0; i < SIZE/2; i++) {
		int temp = c[i];
		c[i] = c[SIZE-1-i];
		c[SIZE-1-i] = temp;
	}
	reverse(c, 10);
	removeOdd(c, 10); // replace all odd elements with zero
	cout << isPalindrome("atoyota") << '\n';
	cout << isPalindrome("able was i ere i saw elba") << '\n';
	for (int i = 0; i < SIZE; i++)
		cout << c[i] << ' ';
	cout << '\n';
	
	print(c, 10);
  char words[] = "this is a test";
	devowelize(words); // remove all aeiou --> ths s  tst\0









	string s = "abc";

	for (int i = 0; i < 10; i++)
		s += "def";
}

int main() {
	string a = "testing";
	// return a string that is the reverse of a without changing a
	string b = reverse(a);
	cout << b << '\n\'; // should print 'gnitset'

	// next implement function remove_vowels which should
	// return a string with the letters a, e, i, o and u removed
	cout << remove_vowels(a) << '\n'; // should print 'tstng'
}

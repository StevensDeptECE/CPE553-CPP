/*
	Implement this program using separate .cc and .hh files

*/

int main() {
	try {
		Person p1("Fred", "Astaire"); // create a person with first and last name
		p1.setLive(false);
		p1.eat(); // in this case, since Fred Astaire is dead, throw exception
		
		cout << p1 << '\n'; // "Fred Astaire is dead"
		
		Person p1("Min", "Song"); // create a person with first and last name
		p1.setLive(true);
		cout << p1 << '\n'; // "Min Song is alive"
	} catch (const char* msg) {
		cout << msg << '\n';
	}

}

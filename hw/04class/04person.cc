int main() {
	/*
		create a class person that implements the following methods
		A person object should be created with a first and last name
		and age = 0
		Every time the birthday() method is called, the age should increase by 1

		
	 */
	person p("Dov", "Kruger");
	p.birthday(); // 1 year old
	p.birthday(); // 2 years old

	cout << p << '\n'; // should print Person firstname=Dov lastname=Kruger age=2
}

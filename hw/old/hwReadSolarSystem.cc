int main() {
	ifstream f("solarsystem.dat"); // this file may be obtained from the current directory/data
	vector<SphericalBody> bodies;
	while (!f.eof()) {
		// read a single line from the file
		// create a spherical body
		// add it to the list
	}

	// print out all bodies
	for (auto b : bodies) {
		cout << b << '\n';
	}
}

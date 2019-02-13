class Body {

};

int main() {
	//         name      mass(kg) x y z  radius (m)
	Body earth("earth", 5.972e24, 0,0,0, 6.371e6);
	Body moon("moon",   7.34767309e22, 384.400e6,0,0,  1.737e6);
	cout << earth << '\n';
	cout << moon << '\n';
}
	

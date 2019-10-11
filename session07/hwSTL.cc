
int main() {
	Model m("test.stl");
	m.add(new Cube(30));
	m.add(new Cylinder(10, 20)); // r=10, h=20
	// if you want to print a cylinder, sides AND TOP and BOTTOM!!!
	// optional: top and bottom + 30 points
	// optional: sphere + 100 points
	//	m.add(new Sphere(15)); // radius=15
	m.save(); // save to STL file
}

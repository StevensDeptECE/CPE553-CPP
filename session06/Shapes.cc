/*
	Cube
	Cylinder
	Sphere (optional)

https://en.wikipedia.org/wiki/STL_(file_format)
	
 */

int main() {
	Design d("test.stl");
	double s = 10;
	Cube c(s);
	c.translate(x,y,z);
	// rotate??
	cout << c.volume() << '\n';
	c.write("out.stl"); // how to get all my shapes into the same file
  d.add(c);
	double r = 10, height  = 20;
	Cylinder cyl(r, height);
	d.add(c);
	d.write();

}

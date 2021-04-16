int main() {
	//translate([0,10,0]) cube(25);
	Cube c(0,10,0, 25); // make a 25x25x25 cube at location (0,10,0)
	c.print("cube.stl");

	//translate([100,0,0]) cylinder(r=20,h=50, $fn=30);
	
	// canter of base circle x=100, y=0, z=0 r=20 h=50, number of facets = 30
	Cylinder cyl(100, 0, 0, 20, 50, 30);
	c.print("cyl.stl");

	//%50 bonus
	// (x,y,z)           r,  numfacets
	Sphere s(-50,50,50,  25, 10);
	s.print("sphere.stl");

	//+%100%
	Drawing d; // constructor, destructor, ...
	d.add(new Cube(0,10,0,25));
	d.add(new Cylinder(100,0,0,20,50,30));
	d.print("drawing.stl");
}

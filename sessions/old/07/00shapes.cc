
int main() {
	STLFile f("test.stl")
	Cube c(10); // (0,0,0)
	f.add(&c)
	Cylinder cyl(5, 10); // (0,0,0)
	cyl.translate(10,0,0);
	f.add(&cyl);
	f.write();
	
}

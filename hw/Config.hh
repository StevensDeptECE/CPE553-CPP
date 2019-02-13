int main() {
	Config conf("test.conf");
	conf.required("x", "double");

	double x =	conf.get<float>("x", 1.28);
	double y =	conf.get<int>("y", 5);
}

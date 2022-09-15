/*
	Author: 

 */
void print(const uint64_t a[], uint32_t len) {

}

int main() {
	// write a function that computes the sum of squares
	uint64_t s = sumsq(1, 5); // 1*1 + 2*2 + 3*3 + 4*4 + 5*5

	// look up the floating point library in the notes use atan2
	/*
        ang
       /|
      / |
     /  | 4
    /   |
    -----
      3
	 */
	double ang = angle(3, 4); // calculate the angle for 3-4-5 right triangle
	cout << ang << '\n'; // in radians

	double deg = 0; // TODO: convert to degrees

	double r = 5;

	double x, y;
	polar2rect(r, ang, x, y);
	cout << "x=" << x << " y=" << y << '\n';

	/*
    1  2  3  4  5
    2  4  6  8  10
    3  6  9  12 15
    4  8  12 16 20
    5  10 15 20 25
	*/
	multtable(5);

	uint64_t a[] = {1, 3, 5, 9};
	cubeit(a, 4); // 1*1*1   3*3*3   5*5*5   9*9*9
	print(a,4);
}


		

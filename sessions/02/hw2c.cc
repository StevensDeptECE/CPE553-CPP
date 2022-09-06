/*
	read in robotpath.dat
  each line contains distance (in meters) and angle (in degrees)
  convert angle to radians
	Good design principle: always keep numbers in one internal format
	in this case, since sin, cos, etc use radians, do all computation
	and store all variables in radians.
	Only convert to degrees to print out

	print out x,y location at each step accurate to 8 digits

  5.0   30
  10.0  45
  5.0   270
 */

int main() {
	ifstream f("robotpath.dat");// no absolute  paths in homework!!!! c:/ NO /Users/dkruger NO!!!

}

class Thing {
private:
	double x; // the default is to copy every bit.
	int y;    // for any value inside the object, this works
	char z;
	int arr[10];
  Matrix m;
	
	int* p; // for copying a pointer the default MAKES NO SENSE
	// the default creates two objects that point to the same place

	// 1. The two objects are NOT COPIES. They share memory
	// 2. When the first object deletes the memory, the second object will crash the program when it accesses or tries to delete again
};

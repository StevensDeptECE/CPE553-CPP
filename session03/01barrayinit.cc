int main() {
	int a[10]; // uninitialized
	int b[10] = {5}; // initialized to all zero b[0] = 5, all the rest are zero
	int c[] = {5, 4, 3}; // c[0] = 5 c[1]=4 c[2] =3

	int d[4][2] = {
								 {5},
								 {2, -1},
								 {3, -5}
	};

	int arduino[2][2][2][2][2][20];

	// big arrays cannot be on the stack. More later...	int big[1000000];
}

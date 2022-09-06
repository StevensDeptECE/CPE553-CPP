int main() {
	int a = 5;
	const int b = 6;
	int* p = &a;
	int* q1 = &b;
	*q1 = 7;
	const int* q2 = &b;
	*q2 = 8;
	int* const q3 = &a;
	*q3 = 44;
	q3 = q2;
}

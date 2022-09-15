void print(const int x[], int n) {
	cout << sizeof(x) << '\n'; // 8
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
}

void print2(const int* const p, int n) {

}

int main() {
	int x[10];
	cout << sizeof(x) << '\n'; //  40
	print(x, 10);

}

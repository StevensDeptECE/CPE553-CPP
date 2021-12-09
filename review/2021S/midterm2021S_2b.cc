class Bank {
public:
	double* vault;

	void deposit(double amt) {}
	void withdraw(double amt) {}

};

int main() {
  Bank  b;
	double steal = b.vault[0];
}

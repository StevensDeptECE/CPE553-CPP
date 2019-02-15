class Account {
public:
	void deposit(double amt) throw(TransactionFailed);
	bool withdraw() throw(TransactionFailed);
};

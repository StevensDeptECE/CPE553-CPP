int main() {
	// implement the choose function.
	//Compute in double precision to avoid overflow
	cout << choose(52, 6) << '\n'; // 52!/(6! * (52-6)!)
	cout << choose(60, 20) << '\n'; // 60! / (20! (60-40)!)
}

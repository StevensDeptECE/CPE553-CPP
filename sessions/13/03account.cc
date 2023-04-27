#include <thread>
#include <iostream>
using namespace std;

class Account {
private:
  uint64_t balance;
public:
  Account() : balance(0) {}
  void deposit(uint64_t amt) {
    balance += amt;
  }

  bool withdraw(uint64_t amt) {
    if (amt > balance)
      return false;
    balance -= amt;
    return true;
  }

  uint64_t getBalance() const {
     return balance;
  }

};

constexpr uint64_t amt = 1'000'000'000ULL;
Account a;

// deposit amt $ 1 at a time
void deposit1() {
  for (uint64_t i = 0; i < amt; i++)
    a.deposit(1);
}

// withdraw amt $ 1 at a time
void withdraw1() {
  for (uint64_t i = 0; i < amt; i++)
    a.withdraw(1);
}

int main() {
    a.deposit(100);

    if (!a.withdraw(200)) {
        cout << "withdraw failed\n";
    }

    uint64_t balance = a.getBalance();
    cout << "balance=" << balance << '\n';

    thread t1(deposit1);
    thread t2(withdraw1);
    t1.join();
    t2.join();
    cout << "balance=" << a.getBalance() << '\n';

}
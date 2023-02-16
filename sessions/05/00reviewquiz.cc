int fact(int n) {

    
}

int main() {
    int a = 2 / 3 * 3; // a= 0 
    int b = 3 / 2 * 3; // b=3
    int c = 6 % 2 * 5; // c = 0
    int d = 6 % 5 * 2; // d = 2
    double e = 3 / 2;      // e = 1.0
    double f = 3 / 2 * 3;  // f = 3.0
    double g = 3.0 / 1.5;  // g = 2.0
    uint64_t h = 3.9 / 2;  // h = 1

    for (int i = 1; i < 10; i*= 3)
      cout << i << ' ';  // 1 3 9 

    for (int = 100; i > 10; i = (i-4) / 3)
      cout << i << ' '; // 100 32 

    for (int i = 1; i < 30; i += 2)
      if (i % 3 == 0)
        cout << i << " ";   // 3 9 15 21 27

    cout << fact(5);
}




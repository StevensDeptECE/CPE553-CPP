#include <string>
#include <iostream>

using namespace std;

void replace(string& str, char base, char repl) {
  
  for (int i = 0; i < str.length(); i++){
    if (str[i] == base) { str[i]=repl; }
    cout << "str=" << str << '\n';
  }
  
/*
  for (auto c : str)
    if (c == base) { c=repl; }
*/

}

int main() {
  string a = "abacdaaabacccc";
  replace(a, 'a', 'x');
  cout << a << '\n';
  const string b = "hallo";
  //illegal, b is const! replace(b, 'a', 'y');

  // illegal to pass string& from an old-style string
  //replace("hello", 'e', 'q');
}

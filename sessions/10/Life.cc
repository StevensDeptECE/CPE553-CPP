
class Life {
private:
  uint8_t* life; // +100% if you can do this with just 1 boadrd 
  uint8_t* next; 
public:
  Life(uint32_t rows, uint32_t cols){}

};

int main() {
    https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#Rules
    ifstream f("my.life.txt");
    Life life(f);
    for (int i = 0; i< 10; i++) {
        cout << life;
        life.next();
    }
    Life life2 = life; // make sure copy constructor doesn't crash
    life2 = life; // make sure operator = works
     
}
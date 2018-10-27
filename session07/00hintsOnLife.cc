class Life {
private:
	int board[12][12];
	int next[12][12];
public:
   Life(int timesteps, int printEvery) {

   }

   void step() {
   }
   
for (int i ...
  for (int j ...
     next[i][j] = 

     board[i+1][j] + board[i-1][j] + board[i][j+1] + board[i][j-1] +
     board[i+1][j-1]

for (i ..
  for j
    board[i][j] = next[i][j]

//swap(board, next)

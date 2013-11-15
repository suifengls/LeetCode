/*
  Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

  A region is captured by flipping all 'O's into 'X's in that surrounded region .
  
  For example,
   X X X X
   X O O X
   X X O X
   X O X X
  After running your function, the board should be:
   X X X X
   X X X X
   X X X X
   X O X X
*/

class Solution {
public:
  void solve(vector<vector<char>> &board) {
    if(board.empty())
      return;
    int m = board.size(), n = board[0].size();
    for(int i = 0; i < m; ++i)
      for(int j = 0; j < n; ++j)
	if(i == 0 || i == m-1 || j == 0 || j == n-1)
	  bfs(board, i, j, m, n);
    for(int i = 0; i < m; ++i)
      for(int j = 0; j < n; ++j)
	board[i][j] = (board[i][j] == 'P') ? 'O' : 'X';
  }
  void bfs(vector<vector<char>> &board, int x, int y, int m, int n)
  {
    if(board[x][y] != 'O')
      return;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty())
      {
	int i = q.front().first, j = q.front().second;
	q.pop();
	if(i < 0 || i >= m || j < 0 || j >= n)
	  continue;
	if(board[i][j] != 'O')
	  continue;
	board[i][j] = 'P';
	q.push(make_pair(i-1, j));
	q.push(make_pair(i+1, j));
	q.push(make_pair(i, j-1));
	q.push(make_pair(i, j+1));
      }
  }
};

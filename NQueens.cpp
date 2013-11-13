/*
  The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

  Given an integer n, return all distinct solutions to the n-queens puzzle.
  
  Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

  For example,
  There exist two distinct solutions to the 4-queens puzzle:
  
  [
   [".Q..",  // Solution 1
   "...Q",
   "Q...",
   "..Q."],
   
   ["..Q.",  // Solution 2
   "Q...",
   "...Q",
   ".Q.."]
  ]
*/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
	vector<vector<string> > queen;
	vector<int> pos(n, -1);
	queenHelper(queen, pos, n, 0);
	return queen;
    }
    void queenHelper(vector<vector<string> > &queen, vector<int> &pos, int n, int row)
	{
	    if(row == n)
	    {
		vector<string> Q(n, string(n, '.'));
		print(Q, pos, n);
		queen.push_back(Q);
	    }
	    else
	    {
		for(int col = 0; col < n; ++col)
		{
		    pos[row] = col;
		    if(isValid(pos, row))
			queenHelper(queen, pos, n, row+1);
		}
	    }
	}
    bool isValid(vector<int> pos, int row)
	{
	    for(int i = 0; i < row; ++i)
		if((pos[i] == pos[row]) || (row-i == abs(pos[i]-pos[row])))
		    return false;
	    return true;
	}
    void print(vector<string> &queen, vector<int> &pos, int n)
	{
	    for(int i = 0; i < n; ++i)
		queen[i][pos[i]] = 'Q';
	}
};

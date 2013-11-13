/*
  Follow up for N-Queens problem.

  Now, instead outputting board configurations, return the total number of distinct solutions.
*/

class Solution {
public:
    int totalNQueens(int n) {
	int result = 0;
	int *pos = new int[n];
	queenHelper(result, pos, n, 0);
	delete [] pos;
	return result;
    }
    void queenHelper(int &result, int pos[], int n, int row)
	{
	    if(n == row)
		++result;
	    else
	    {
		for(int col = 0; col < n; ++col)
		{
		    pos[row] = col;
		    if(isValid(pos, row))
			queenHelper(result, pos, n, row+1);
		}
	    }
	}
    bool isValid(int pos[], int row)
	{
	    for(int i = 0; i < row; ++i)
		if((pos[row] == pos[i]) || (row-i == abs(pos[row]-pos[i])))
		    return false;
	    return true;
	}
};

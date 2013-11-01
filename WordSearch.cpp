/*
  Given a 2D board and a word, find if the word exists in the grid.

  The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

  For example,
  Given board =

  [
    ["ABCE"],
    ["SFCS"],
    ["ADEE"]
  ]
  word = "ABCCED", -> returns true,
  word = "SEE", -> returns true,
  word = "ABCB", -> returns false.
*/
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
	if(word.empty())
	    return true;
	if(board.empty())
	    return false;
	int m = board.size(), n = board[0].size();
	vector<vector<bool> > visited(m, vector<bool>(n, false));
	for(int i = 0; i < m; ++i)
	    for(int j = 0; j < n; ++j)
		if(searchHelper(board, visited, word, 0, i, j))
		    return true;
	return false;
    }
    bool searchHelper(vector<vector<char> > &board, vector<vector<bool> > &visited, string word, int l, int i, int j)
        {
	    if(word.size() == l)
		return true;
	    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
		return false;
	    if(board[i][j] != word[l] || visited[i][j])
		return false;
	    visited[i][j] = true;
	    if(searchHelper(board, visited, word, l+1, i-1, j))
		return true;
	    if(searchHelper(board, visited, word, l+1, i+1, j))
		return true;
	    if(searchHelper(board, visited, word, l+1, i, j-1))
		return true;
	    if(searchHelper(board, visited, word, l+1, i, j+1))
		return true;
	    visited[i][j] = false;
	    return false;
	}
};

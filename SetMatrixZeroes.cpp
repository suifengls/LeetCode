/*
  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
  
  Follow up:
  Did you use extra space?
  A straight forward solution using O(mn) space is probably a bad idea.
  A simple improvement uses O(m + n) space, but still not the best solution.
  Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
	if(matrix.empty())
	    return;
	int m = matrix.size(), n = matrix[0].size();
	vector<bool> row(m, false), col(n, false);
	for(int i = 0; i < m; ++i)
	    for(int j = 0; j < n; ++j)
		if(matrix[i][j] == 0)
		{
		    row[i] = true;
		    col[j] = true;
		}
	for(int i = 0; i < m; ++i)
	    for(int j = 0; j < n; ++j)
		if(row[i] || col[j])
		    matrix[i][j] = 0;
	return;
    }
};

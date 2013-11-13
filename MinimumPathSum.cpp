/*
  Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

  Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
	int m = grid.size(), n = grid[0].size();
	vector<int> sum(n, 0);
	sum[0] = grid[0][0];
	for(int i = 1; i < n; ++i)
	    sum[i] = sum[i-1] + grid[0][i];
	for(int i = 1; i < m; ++i)
	{
	    sum[0] += grid[i][0];
	    for(int j = 1; j < n; ++j)
	    {
		sum[j] = min(sum[j-1], sum[j]) + grid[i][j];
	    }
	}
	return sum[n-1];
    }
};

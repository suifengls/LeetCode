/*
  Follow up for "Unique Paths":

  Now consider if some obstacles are added to the grids. How many unique paths would there be?

  An obstacle and empty space is marked as 1 and 0 respectively in the grid.

  For example,
  There is one obstacle in the middle of a 3x3 grid as illustrated below.

  [
    [0,0,0],
    [0,1,0],
    [0,0,0]
  ]
  The total number of unique paths is 2.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	vector<vector<int> > path(m, vector<int>(n, 0));
	bool obs = true;
	for(int i = 0; i < m; ++i)
	{
	    if(obstacleGrid[i][0])
		obs = false;
	    if(obs)
		path[i][0] = 1;
	}
	obs = true;
	for(int j = 0; j < n; ++j)
	{
	    if(obstacleGrid[0][j])
		obs = false;
	    if(obs)
		path[0][j] = 1;
	}
	for(int i = 1; i < m; ++i)
	{
	    for(int j = 1; j < n; ++j)
	    {
		if(obstacleGrid[i][j])
		    path[i][j] = 0;
		else
		    path[i][j] = path[i-1][j] + path[i][j-1];
	    }
	}
	return path[m-1][n-1];
    }
};

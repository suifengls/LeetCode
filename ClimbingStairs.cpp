/*
  You are climbing a stair case. It takes n steps to reach to the top.
  
  Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
	if(n < 1)
	    return 0;
	int dp[n];
	dp[0] = 1; // first stair
	dp[1] = 2; // second stair
	for(int i = 2; i < n; ++i)
	    dp[i] = dp[i-1] + dp[i-2];
	return dp[n-1];
    }
};

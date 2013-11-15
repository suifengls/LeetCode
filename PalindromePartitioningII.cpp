/*
  Given a string s, partition s such that every substring of the partition is a palindrome.

  Return the minimum cuts needed for a palindrome partitioning of s.
  
  For example, given s = "aab",
  Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:
  int minCut(string s) {
    int n = s.size();
    bool palin[n][n];
    int cut[n+1];
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
	palin[i][j] = false;
    for(int i = 0; i <= n; ++i)
      cut[i] = n-i-1;
    for(int i = n-1; i >= 0; --i)
      {
	for(int j = i; j < n; ++j)
	  {
	    if(s[i] == s[j] && (j-i < 2 || palin[i+1][j-1]))
	      {
		palin[i][j] = true;
		cut[i] = min(cut[i], cut[j+1]+1);
	      }
	  }
      }
    return cut[0];
  }
};

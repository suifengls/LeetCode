/*
  Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

  You have the following 3 operations permitted on a word:

  a) Insert a character
  b) Delete a character
  c) Replace a character
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
	int l1 = word1.length(), l2 = word2.length();
	vector<vector<int> > dist(l1+1, vector<int>(l2+1, 0));
	for(int i = 0; i <= l1; ++i)
	    dist[i][0] = i;
	for(int j = 0; j <= l2; ++j)
	    dist[0][j] = j;
	for(int i = 1; i <= l1; ++i)
	{
	    for(int j = 1; j <= l2; ++j)
	    {
		if(word1[i-1] == word2[j-1])
		    dist[i][j] = dist[i-1][j-1];
		else
		    dist[i][j] = min(min(dist[i-1][j], dist[i][j-1]), dist[i-1][j-1]) + 1;
	    }
	}
	return dist[l1][l2];
    }
};

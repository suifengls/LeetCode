/*
  Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
  
  For example,
  If n = 4 and k = 2, a solution is:
  
  [
   [2,4],
   [3,4],
   [2,3],
   [1,2],
   [1,3],
   [1,4],
  ]
*/

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
	vector<vector<int> > result;
	vector<int> com;
	comHelper(result, com, n, k, 0);
	return result;
    }
    void comHelper(vector<vector<int> > &result, vector<int> &com, int n, int k, int s)
        {
	    if(com.size() == k)
		result.push_back(com);
	    else
	    {
		for(int i = s+1; i <= n; ++i)
		{
		    com.push_back(i);
		    comHelper(result, com, n, k, i);
		    com.pop_back();
		}
	    }
	}
};

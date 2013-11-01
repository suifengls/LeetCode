/*
  Given a set of distinct integers, S, return all possible subsets.

  Note:
  Elements in a subset must be in non-descending order.
  The solution set must not contain duplicate subsets.
  For example,
  If S = [1,2,3], a solution is:

  [
    [3],
    [1],
    [2],
    [1,2,3],
    [1,3],
    [2,3],
    [1,2],
    []
  ]
*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
	vector<vector<int> > result;
	vector<int> sets;
	sort(S.begin(), S.end());
	setHelper(S, result, sets, 0);
	return result;
    }
    void setHelper(vector<int> &S, vector<vector<int> > &result, vector<int> &sets, int k)
        {
	    result.push_back(sets);
	    for(int i = k; i < S.size(); ++i)
	    {
		sets.push_back(S[i]);
		setHelper(S, result, sets, i+1);
		sets.pop_back();
	    }
	}
};

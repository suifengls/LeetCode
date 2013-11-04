/*
  Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

  The same repeated number may be chosen from C unlimited number of times.

  Note:
  All numbers (including target) will be positive integers.
  Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
  The solution set must not contain duplicate combinations.

  For example, given candidate set 2,3,6,7 and target 7,
  A solution set is:
  [7]
  [2, 2, 3]
*/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	vector<vector<int> > result;
	vector<int> com;
	if(candidates.empty())
	    return result;
	sort(candidates.begin(), candidates.end());
	sumHelper(candidates, target, result, com, 0, 0);
	return result;
    }
    void sumHelper(vector<int> &candidates, int target, vector<vector<int> > &result, vector<int> &com, int sum, int k)
        {
	    if(sum > target)
		return;
	    else if(sum == target)
		result.push_back(com);
	    else
	    {
		for(int i = k; i < candidates.size(); ++i)
		{
		    com.push_back(candidates[i]);
		    sumHelper(candidates, target, result, com, sum+candidates[i], i);
		    com.pop_back();
		}
	    }
	}
};

/*
  Given a collection of numbers, return all possible permutations.

  For example,
  [1,2,3] have the following permutations:
  [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int> > result;
	permHelper(result, num, 0);
	return result;
    }
    void permHelper(vector<vector<int> > &result, vector<int> &num, int k)
        {
	    if(k == num.size()-1)
		result.push_back(num);
	    else
	    {
		for(int i = k; i < num.size(); ++i)
		{
		    swap(num[i], num[k]);
		    permHelper(result, num, k+1);
		    swap(num[i], num[k]);
		}
	    }
	}
};

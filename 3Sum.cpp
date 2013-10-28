/*
  Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
  
  Note:
  Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
  The solution set must not contain duplicate triplets.
  For example, given array S = {-1 0 1 2 -1 -4},
  
  A solution set is:
  (-1, 0, 1)
  (-1, -1, 2)
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int> > result;
	/* less than 3 numbers */
	if(num.size() < 3)
	    return result;
	sort(num.begin(), num.end());
	/* num[i] <= 0 */
	for(int i = 0; i < num.size()-2 && num[i] <= 0; ++i)
	{
	    /* avoid duplicate */
	    if(i > 0 && num[i] == num[i-1])
		continue;
	    int j = i+1, k = num.size()-1;
	    while(j < k)
	    {
		int sum = num[i] + num[j] + num[k];
		if(sum == 0)
		{
		    vector<int> triplet;
		    triplet.push_back(num[i]);
		    triplet.push_back(num[j]);
		    triplet.push_back(num[k]);
		    result.push_back(triplet);
		    /* move j and k both one step */
		    ++j;
		    --k;
		    /* avoid duplicate */
		    while(j < k && num[j] == num[j-1])
			++j;
		    while(j < k && num[k] == num[k+1])
			--k;
		}
		else if(sum > 0)
		    --k;
		else
		    ++j;
	    }
	}
	return result;
    }
};

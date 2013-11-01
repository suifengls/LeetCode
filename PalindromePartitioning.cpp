/*
  Given a string s, partition s such that every substring of the partition is a palindrome.

  Return all possible palindrome partitioning of s.

  For example, given s = "aab",
  Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
	vector<vector<string> > result;
	vector<string> part;
	partHelper(result, part, s, 0);
	return result;
    }
    bool isPal(string s, int start, int end)
        {
	    while(start < end)
	    {
		if(s[start] != s[end])
		    return false;
		++start;
		--end;
	    }
	    return true;
	}
    void partHelper(vector<vector<string> > &result, vector<string> &part, string s, int start)
        {
	    if(start == s.size())
		result.push_back(part);
	    else
	    {
		for(int i = start; i < s.size(); ++i)
		{
		    if(isPal(s, start, i))
		    {
			part.push_back(s.substr(start, i-start+1));
			partHelper(result, part, s, i+1);
			part.pop_back();
		    }
		}
	    }
	}
};

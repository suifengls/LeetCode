/*
  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

  For example, given n = 3, a solution set is:

  "((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
	vector<string> result;
	genHelper(n, 0, 0, result, "");
	return result;
    }
    void genHelper(int n, int l, int r, vector<string> &result, string p)
	{
	    if(l > n)
		return;
	    if(l == n && r == n)
		result.push_back(p);
	    else
	    {
		genHelper(n, l+1, r, result, p + "(");
		if(l > r)
		    genHelper(n, l, r+1, result, p + ")");
	    }
	}
};

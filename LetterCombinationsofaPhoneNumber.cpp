/*
  Given a digit string, return all possible letter combinations that the number could represent.

  A mapping of digit to letters (just like on the telephone buttons) is given below.

  Input:Digit string "23"
  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
  Note:
  Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
	string num[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> result;
	string comb(digits);
	combHelper(digits, result, num, 0, comb);
	return result;
    }
    void combHelper(string &digits, vector<string> &result, string num[], int k, string comb)
        {
	    if(k == digits.size())
		result.push_back(comb);
	    else
	    {
		string dig = num[digits[k] - '0'];
		for(int j = 0; j < dig.size(); ++j)
		{
		    comb[k] = dig[j];
		    combHelper(digits, result, num, k+1, comb);
		}
	    }
	}
};

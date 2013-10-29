/*
  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
  
  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
	if(s.size() % 2 == 1)
	    return false;
	stack<char> stk;
	int i = 0;
	while(i < s.size())
	{
	    if(s[i] == '(' || s[i] == '{' || s[i] == '[')
		stk.push(s[i]);
	    else
	    {
		if(stk.empty())
		    return false;
		if(s[i] == ')')
		{
		    if(stk.top() == '(')
			stk.pop();
		    else
			return false;
		}
		else if(s[i] == '}')
		{
		    if(stk.top() == '{')
			stk.pop();
		    else
			return false;
		}
		else if(s[i] == ']')
		{
		    if(stk.top() == '[')
			stk.pop();
		    else
			return false;
		}
	    }
	    ++i;
	}
	/* stack is not empty, left paratheses left */
	if(!stk.empty())
	    return false;
	return true;
    }
};

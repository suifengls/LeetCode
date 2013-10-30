/*
  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

  For example,
  "A man, a plan, a canal: Panama" is a palindrome.
  "race a car" is not a palindrome.
  
  Note:
  Have you consider that the string might be empty? This is a good question to ask during an interview.
  
  For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome1(string s) {
	if(s.empty())
	    return true;
	int l = 0, r = s.size()-1;
	while(l < r)
	{
	    while(l < r && (!isalpha(s[l]) && !isdigit(s[l])))
		++l;
	    while(l < r && (!isalpha(s[r]) && !isdigit(s[r])))
		--r;
	    if(l >= r)
		return true;
	    if(tolower(s[l]) != tolower(s[r]))
		return false;
	    ++l;
	    --r;
	}
	return true;
    }
};

class Solution {
public:
    bool isPalindrome2(string s) {
	for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
	{
	    while (i < j && !isalnum(s[i])) i++;
	    while (i < j && !isalnum(s[j])) j--;

	    if (tolower(s[i]) != tolower(s[j]))
		return false;
	}
	return true;
    }
};

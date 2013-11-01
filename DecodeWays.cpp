/*
  A message containing letters from A-Z is being encoded to numbers using the following mapping:
  
  'A' -> 1
  'B' -> 2
  ...
  'Z' -> 26
  Given an encoded message containing digits, determine the total number of ways to decode it.
  
  For example,
  Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
  
  The number of ways decoding "12" is 2.
*/
class Solution {
public:
    int numDecodings(string s) {
	if(s.empty() || s == "0")
	    return 0;
	vector<int> ways(s.size()+1, 1);
	for(int i = s.size()-1; i >= 0; --i)
	{
	    if(s[i] == '0')
		ways[i] = 0;
	    else
		ways[i] = ways[i+1];
	    if(i+1 < s.size() && ((s[i] == '1') || (s[i] == '2' && s[i+1] - '0' <= 6)))
		ways[i] += ways[i+2];
	}
	return ways[0];
    }
};

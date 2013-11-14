/*
  Given a string containing only digits, restore it by returning all possible valid IP address combinations.
  
  For example:
  Given "25525511135",
  
  return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
	vector<string> result;
	if(s.size() < 4 || s.size() > 12)
	    return result;
	ipHelper(s, result, "", 0, 0);
	return result;
    }
    void ipHelper(string s, vector<string> &result, string ip, int k, int dot)
	{
	    if(ip.size() == s.size()+3 && dot == 3)
		result.push_back(ip);
	    else
	    {
		for(int i = 1; i <= 3; ++i)
		{
		    if(isValid(s.substr(k, i), i))
		    {
			if(k+i == s.size())
			    ipHelper(s, result, ip + s.substr(k,i), k+i, dot);
			else if(k+i < s.size())
			    ipHelper(s, result, ip + s.substr(k,i) + ".", k+i, dot+1);
		    }
		}
	    }
	}
    bool isValid(string s, int n)
	{
	    if(n > 1 && s[0] == '0')
		return false;
	    int ip = atoi(s.c_str());
	    if(ip < 0 || ip > 255)
		return false;
	    return true;
	}
};

/*
  Given a roman numeral, convert it to an integer.

  Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    int romanToInt(string s) {
	map<char, int> rom;
	rom['I'] = 1;
	rom['V'] = 5;
	rom['X'] = 10;
	rom['L'] = 50;
	rom['C'] = 100;
	rom['D'] = 500;
	rom['M'] = 1000;
	int n = 0;
	for(int i = 0; i < s.size(); ++i)
	{
	    n += rom[s[i]];
	    if(i+1 < s.size())
	    {
		if(s[i] == 'I' && (s[i] == 'V' || s[i] == 'X'))
		    n -= 2;
		else if(s[i] == 'X' && (s[i] == 'L' || s[i] == 'C'))
		    n -= 20;
		else if(s[i] == 'C' && (s[i] == 'D' || s[i] == 'M'))
		    n -= 200;
	    }
	}
	return n;
    }
};

/*
  Given an integer, convert it to a roman numeral.

  Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string intToRoman(int num) {
	map<int, string> rom;
	rom[1] = "I";
	rom[5] = "V";
	rom[10] = "X";
	rom[50] = "L";
	rom[100] = "C";
	rom[500] = "D";
	rom[1000] = "M";
	string S("");
	int curr = 1;
	while(num > 0)
	{
	    string R("");
	    int res = num%10;
	    num /= 10;
	    if(res > 0)
	    {
		if(res == 4)
		{
		    res = 0;
		    R = rom[curr] + rom[5*curr];
		}
		else if(res == 9)
		{
		    res = 0;
		    R = rom[curr] + rom[10*curr];
		}
		else if(res >= 5)
		{
		    R = rom[5*curr];
		    res -= 5;
		}
		while(res > 0)
		{
		    --res;
		    R += rom[curr];
		}
	    }
	    S = R + S;
	    curr *= 10;
	}
	return S;
    }
};

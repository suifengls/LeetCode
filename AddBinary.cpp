/*
  Given two binary strings, return their sum (also a binary string).

  For example,
  a = "11"
  b = "1"
  Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
	int i = a.size()-1, j = b.size()-1;
	string s("");
	int carry = 0;
	while(i >= 0 || j >= 0 || carry)
	{
	    int v1 = 0, v2 = 0;
	    if(i >= 0)
		v1 = a[i] - '0';
	    if(j >= 0)
		v2 = b[j] - '0';
	    int sum = v1 + v2 + carry;
	    carry = sum / 2;
	    char d = ((sum%2) + '0');
	    s = d + s;
	    --i;
	    --j;
	}
	return s;
    }
};

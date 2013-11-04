/*
  Given two numbers represented as strings, return multiplication of the numbers as a string.
  
  Note: The numbers can be arbitrarily large and are non-negative.
*/
class Solution {
public:
    string multiply1(string num1, string num2) {
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	string result(num1.size()+num2.size()+1, '0');
	for(int i = 0; i < num1.size(); ++i)
	{
	    int carry = 0;
	    int n1 = num1[i] - '0';
	    for(int j = 0; j < num2.size(); ++j)
	    {
		int n2 = num2[j] - '0';
		int mul = n1*n2 + carry + (result[i+j]-'0');
		carry = mul/10;
		result[i+j] = mul%10 + '0';
	    }
	    if(carry > 0)
		result[i+num2.size()] = carry + '0';
	}
	reverse(result.begin(), result.end());
	int k = 0;
	while(k < result.size() && result[k] == '0')
	    ++k;
	if(k == result.size())
	    return "0";
	return result.substr(k);
    }
};

class Solution {
public:
    string multiply2(string num1, string num2) {
	string result(num1.size()+num2.size(), '0');
	for(int i = num1.size()-1; i >= 0; --i)
	{
	    int carry = 0;
	    for(int j = num2.size()-1; j >= 0; --j)
	    {
		int mul = carry + (num1[i]-'0') * (num2[j]-'0') + result[i+j+1]-'0';
		carry = mul/10;
		result[i+j+1] = mul%10 + '0';
	    }
	    result[i] += carry;
	}
	while(result.size() > 1 && result[0] == '0')
	    result.erase(result.begin());
	return result;
    }
};

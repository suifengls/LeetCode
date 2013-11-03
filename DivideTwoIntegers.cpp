/*
  Divide two integers without using multiplication, division and mod operator.
*/

class Solution {
public:
    int divide1(int dividend, int divisor) {
	long long a = abs((long long) dividend);
	long long b = abs((long long) divisor);
	int result = 0;
	while(a >= b)
	{
	    int i = 0;
	    while((b << i)  <= a)   // recompute the smaller values again and again
		++i;
	    a -= b << (i-1);
	    result += 1 << (i-1);
	}
	if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
	    result = -result;
	return result;
    }
};

class Solution {
public:
    int divide2(int dividend, int divisor) {
	long long a = abs((long long) dividend);
	long long b = abs((long long) divisor);
	int result = 0;
	while(a >= b)
	{
	    long long c = b;
	    for(int i = 0; a >= c; ++i, c <<= 1)
	    {
		a -= c;
		result += 1 << i;
	    }
	}
	if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
	    result = -result;
	return result;
    }
};

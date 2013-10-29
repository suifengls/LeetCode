/*
  Implement pow(x, n).
*/

class Solution {
public:
    double pow(double x, int n) {
	if(n == 0)
	    return 1;
	bool rev = false;
	if(n < 0)
	{
	    n = -n;
	    rev = true;
	}
	if(rev)
	    return 1.0/powHelper(x, n);
	else
	    return powHelper(x, n);
    }
    double powHelper(double x, int n)
	{
	    if(n == 0)
		return 1;
	    bool sig = false;
	    if(n%2 == 1)
		sig = true;
	    double half = powHelper(x, n/2);
	    half = half*half;
	    if(sig)
		return x*half;
	    else
		return half;
	}
};

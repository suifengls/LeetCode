/*
  Implement int sqrt(int x).
  
  Compute and return the square root of x.
*/
class Solution {
public:
    int sqrt(int x) {
	long long i = 0, j = x/2 + 1;
	while(i <= j)
	{
	    long long mid = (i+j)/2;
	    long long sq = mid*mid;
	    if(sq == x)
		return mid;
	    else if(sq < x)
		i = mid+1;
	    else
		j = mid-1;
	}
	return j;
    }
};

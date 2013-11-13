/*
  Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

  For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
  the contiguous subarray [4,−1,2,1] has the largest sum = 6.

  click to show more practice.

  More practice:
  If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
	vector<int> sum(n, A[0]);
	for(int i = 1; i < n; ++i)
	{
	    if(A[i] + sum[i-1] > A[i])
		sum[i] = A[i] + sum[i-1];
	    else
		sum[i] = A[i];
	}
	int max = sum[0];
	for(int i = 1; i < n; ++i)
	    if(sum[i] > max)
		max = sum[i];
	return max;
    }
};

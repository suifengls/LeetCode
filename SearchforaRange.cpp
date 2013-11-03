/*
  Given a sorted array of integers, find the starting and ending position of a given target value.

  Your algorithm's runtime complexity must be in the order of O(log n).

  If the target is not found in the array, return [-1, -1].

  For example,
  Given [5, 7, 7, 8, 8, 10] and target value 8,
  return [3, 4].
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
	vector<int> index(2, -1);
	int l = 0, r = n;
	while(l < r)
	{
	    int mid = (l+r)/2;
	    if(A[mid] < target)
		l = mid+1;
	    else
		r = mid;
	}
	if(A[l] != target)
	    return index;
	index[0] = l;
	r = n;
	while(r > l)
	{
	    int mid = (l+r)/2;
	    if(A[mid] > target)
		r = mid;
	    else
		l = mid+1;
	}
	index[1] = r-1;
	return index;
    }
};

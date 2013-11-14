/*
  Follow up for "Search in Rotated Sorted Array":
  What if duplicates are allowed?

  Would this affect the run-time complexity? How and why?

  Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
	int left = 0, right = n-1;
	while(left <= right)
	{
	    int mid = (left+right)/2;
	    if(A[mid] == target)
		return true;
	    else if(A[left] <= A[mid])
	    {
		while(mid > left && A[mid] == A[left])
		    --mid;
		if(A[left] <= target && target <= A[mid])
		    right = mid;
		else
		    left = mid+1;
	    }
	    else
	    {
		while(mid < right && A[mid] == A[right])
		    ++mid;
		if(A[right] >= target && target >= A[mid])
		    left = mid;
		else
		    right = mid-1;
	    }
	}
	return false;
    }
};

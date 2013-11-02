/*
  There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
	int k = m + n;
	if(k % 2 == 1)
	    return medianHelper(A, m, B, n, k/2+1);
	else
	    return (medianHelper(A, m, B, n, k/2) + medianHelper(A, m, B, n, k/2+1))/2;
    }
    double medianHelper(int A[], int m, int B[], int n, int k)
        {
	    if(m > n)
		return medianHelper(B, n, A, m, k);
	    if(m == 0)
		return B[k-1];
	    if(k == 1)
		return min(A[0], B[0]);
	    int a = min(k/2, m);
	    int b = k - a;
	    if(A[a-1] > B[b-1])
		return medianHelper(A, m, B+b, n-b, k-b);
	    else if(A[a-1] < B[b-1])
		return medianHelper(A+a, m-a, B, n, k-a);
	    else
		return A[a-1];
	}
};

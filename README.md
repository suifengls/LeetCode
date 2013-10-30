LeetCode
========

Solve problems in LeetCode http://oj.leetcode.com/.

***

1. Two Sum

       Hashtabl O(n), hashmap[value] = index + 1
       
       Sorting O(nlogn), neet to find index in the origial vector

2. String to Integer

       Use long long to make sure the string can be converted, then check whether it exceeds INT_MAX/INT_MIN.

3. 3 Sum

       Size of vector >= 3

       Three pointers, one move from 0 to n-1, other two are the same as in Two Sum

       Check duplicates

4. Valid Paratheses

       Stack is not empty, all paratheses are left paratheses.

5. Merge Two Sorted Lists

       Use a dummy node, link the next to the new Listnode with the smaller value, then return dummy->next.

6. Implement strStr()

       Use char* directly to compare.

       Check the haystack step by step, if not equal to needle, move to next start point of haystack.

7. Pow(x, n)

        n could be smaller than 0.

	Resursive call: pow(x, n) = pow(x, n/2) * pow(x, n/2) *[x] (if n is odd)

8. Merge Interval

   	Sorting by start point, merge by max(end point) if two intervals intersection (previous.end <= current.start).

9. Linked List Cycle

   	Two pointers, one faster, one slow, then meet together or meet NULL.

10. Insert Interval

    	Usefull of vector insert() and erase().

	Insert: inserting new elements before the element at the specified position.	

	Erase return value: An iterator pointing to the new location of the element that followed the last element erased by the function call. 

11. Valid Number

    	Too many different cases to handle.

	1. 
	   
	strlen():  A C string is as long as the number of characters between the beginning of the string and the terminating null character (without including the terminating null character itself).

	2.

	Use FINITE AUTOMATA: How to construct the state transition graph correctly?

	Reference: http://discuss.leetcode.com/questions/241/valid-number/768
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

12. Clibming Stairs

    	You have two choices, 1 step or 2 steps, dp[i] = dp[i-1] + dp[i-2].

13. Set Matrix Zeroes

    	Save row and column index firstly, then set 0s according to the index we saved.

14. Merge Sorted Array

    	Backward to stoer the larger number from A and B. Only move the rest numbers in B to A if B has numbers left after A has been moved.

15. Validate Binary Search Tree

    	Recursive Problem. Left nodes should locate in [min, parent->val], right nodes should locate in [parent->val, max].

16. Valid Palindrome

    	isalnum(c): Checks whether c is either a decimal digit or an uppercase or lowercase letter.

17. Word Ladder

    	Graph BFS problem. Use a queue and a visited array for BFS without constructing the graph.

18. Add Two Numbers

    	Remember to initialize head as NULL, or dummy head would be another choice.

	Stop condition: while(l1 || l2 || carry)

19. Integer to Roman

    	Left(-) and right(+) for 5s and 10s.

	Convert from low to high.


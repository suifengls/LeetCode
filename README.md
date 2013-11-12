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
		1. strlen():  A C string is as long as the number of characters between the beginning of the string and the terminating null character (without including the terminating null character itself).
		2.Use FINITE AUTOMATA: How to construct the state transition graph correctly?
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

20. Linked List Cycle II

    	Similar to Linked List Cycle. When two pointers meet, move one back to head, then both move step by step, until they two meet again at the beginning node.

21. Roman to Integer

     	When a smaller char is located before a larger char, substract the vale the smaller char points to.

22. Generate Parentheses

    	Make sure number of left parentheses is not smaller than number of right parentheses.

23. Merge k Sorted Lists

    	Call the Merge Tow Sorted Lists k times, you are done!
		Use min-heap to find the min in O(logk), total time complexity O(nlogk).
    	Reference: https://github.com/AnnieKim/LeetCode/blob/master/MergekSortedLists.h

24. Swap Nodes in Pairs

    	Use a dummy head, then swap every pairs two by two. 
		Remember to move previous node two steps forward after swapping a pair.

25. Remove Element

    	Only copy the elements that do not equal to given value in order.

26. Permutation

		Recursive problem: fix first k-1 numbers, swap number k with following numbers one by one, recursive call.

27. Anagrams

		Sort every string, use this string as key, value is the index of the strings that have the same key after sorting.

28. Add Binary

    	Similar to Add Two Numbers. Use string instead of linked list.

29. Sqrt(x)

		Binary search method. Be careful about overflow, using long long.
	
30. Combinations

		DFS. In position k, iterative through k+1 to n.

31. Subsets

		DFS. Similar to Combinations, but stores all subsets into result.

32. Word Search

    	DFS. If current char match the word, traversal its four directions. Use a visited[][] to mark visited or not.
		Put the check into a function for a better structure of code.

33. Decode Ways

      	Dynamic problem. Similar to Climbing Stairs, with some limitations.
		dp[i] = dp[i-1] + dp[i-2], add dp[i-2] if two char can be put together. 

34. Binary Tree Level Order Traversal

    	Use a queue to store the children nodes of current level.

35. Sum Root to Leave Numbers

    	Recursive call to sum left subtree and right subtree.

36. Palindrome Partitioning

    	DFS. If current substring is a palindrome, recursive calls.

37. Median of Two Sorted Arrays

        1. Make sure A is always the shorter one, easy to check empty array.

		2. If one array is empty, return the kth element in B.

		3. Position in shorter array : min(k/2, m); longer array : k - min(k/2, m)

38. Reverse Integer

    	mod() operation works for negative.
		Use long long type to handle numbers out of INT_MAX or INT_MIN.

39. Regular Expression Matching

    	If next char in p is '*', and *s == *p, skip all the same char in s, return isMatch(s, p+2).
		If next char in p is not '*', compare *s and *p, return isMatch(s+1, p+1).
		Reference: http://leetcode.com/2011/09/regular-expression-matching.html

40. Letter Combinations of a Phone Number

    	DFS. Choose a letter in each position every time until all digits are mapped to letters.

41. Remove Nth Node From End of List

    	Two pointers with dummy head.
		Be careful about n or n-1 to the end.

42. Remove Duplicates from Sorted Array

    	Two pointers, if A[i] is not the same as prev, A[k++] = A[i] and prev = A[i].
		Return length k, not (k+1).

43. Divide Two Integers

    	   Use long long to avoid overflow.
	   Cannot use * and / : subtract b << i, result += 1 << i, until a <= b.

44. Search in Rotated Sorted Array

    	   At least one half is still increasing order.

45. Search for a Range

    	   Be careful of index bound!
    	   L points to the index of first target, R points to the next index of last target. 

46. Combination Sum

           DFS. The start index is the same as current due to the repeated element.

47. Multiple Strings

           Reverse two strings, multiple one by one.
	   OR do as what we do to multiple two numbers. 
	   Be careful about index of the result. 

48. Reorder List
    
	   Reverse the last half of the list, then insert each node to thr first half one by one.

49. Binary Tree Preorder Traversal

 	   1. Recursive call, visit the root first.
	   2. Iterative method, use a stack to store right child, then left childe in order.

50. Binary Tree Postorder Traversal

    	   1. Recursive call, visit the root last.
	   2. Iterative method, use a stack.
	   If current node's right/left children is the previous one being visited, visit this node, then pop it;
    else push right node, then push left node.

51. LRU Cache

    	DoubleLinkedList (remove a node without traversal the list) + Hashmap (find a node in O(1))

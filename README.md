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

       Check duplicate
/*
  Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

  For example,
  Given [100, 4, 200, 1, 3, 2],
  The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
  
  Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    unordered_set<int> hashset;
    for(int i = 0; i < num.size(); ++i)
      hashset.insert(num[i]);
    int maxlen = 1;
    for(int i = 0; i < num.size(); ++i)
      {
	int inc = num[i];
	int des = num[i];
	int len = 1;
	if(hashset.find(num[i]) == hashset.end())
	  continue;
	while(hashset.find(inc+1) != hashset.end())
	  {
	    ++len;
	    hashset.erase(++inc);
	  }
	while(hashset.find(des-1) != hashset.end())
	  {
	    ++len;
	    hashset.erase(--des);
	  }
	maxlen = max(maxlen, len);
      }
    return maxlen;
  }
};

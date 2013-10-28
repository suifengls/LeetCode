/*
  Given an array of integers, find two numbers such that they add up to a specific target number.
  
  The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
  
  You may assume that each input would have exactly one solution.
  
  Input: numbers={2, 7, 11, 15}, target=9
  Output: index1=1, index2=2
*/

class Solution {
public
    /* Hashtable, O(n) */
    vector<int> twoSum1(vector<int> &numbers, int target) {
	vector<int> index;
	unordered_map<int, int> hashmap;
	for(int i = 0; i < numbers.size(); ++i)
	{
	    if(hashmap.find(target-numbers[i]) != hashmap.end())
	    {
		index.push_back(min(i+1, hashmap[target-numbers[i]]));
		index.push_back(max(i+1, hashmap[target-numbers[i]]));
	    }
	    else
		hashmap[numbers[i]] = i+1;
	}
	return index;
    }

    /* Sorting and Two pointers O(nlogn) */
    vector<int> twoSum2(vector<int> &numbers, int target) {
	vector<int> index;
	vector<int> orig(numbers.begin(), numbers.end());
	int index1 = 0, index2 = numbers.size()-1;
	sort(numbers.begin(), numbers.end());
	while(index1 < index2)
	{
	    int sum = numbers[index1] + numbers[index2];
	    if(sum == target)
	    {
		/* Be careful to find the original index */
		for(int i = 0; i < orig.size(); ++i)
		{
		    if(orig[i] == numbers[index1])
		    {
			index1 = i+1;
			break;
		    }
		}
		for(int i = 0; i < orig.size(); ++i)
		{
		    if(i != index1-1 && orig[i] == numbers[index2])
		    {
			index2 = i+1;
			break;
		    }
		}
		index.push_back(min(index1, index2));
		index.push_back(max(index1, index2));
		break;
	    }
	    else if(sum > target)
		--index2;
	    else
		++index1;
	}
	return index;
    }
};

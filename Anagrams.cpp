/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
	vector<string> result;
	map<string, vector<int> > hashmap;
	for(int i = 0; i < strs.size(); ++i)
	{
	    string tmp = strs[i];
	    sort(tmp.begin(), tmp.end());
	    hashmap[tmp].push_back(i);
	}
	for(map<string, vector<int> >::iterator it = hashmap.begin(); it != hashmap.end(); ++it)
	{
	    if(it->second.size() > 1)
		for(int i = 0; i < it->second.size(); ++i)
		    result.push_back(strs[it->second[i]]);
	}
	return result;
    }
};

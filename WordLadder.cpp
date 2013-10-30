/*
  Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

  Only one letter can be changed at a time
  Each intermediate word must exist in the dictionary
  For example,

  Given:
  start = "hit"
  end = "cog"
  dict = ["hot","dot","dog","lot","log"]
  As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
  return its length 5.

  Note:
  Return 0 if there is no such transformation sequence.
  All words have the same length.
  All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
	int length = 2, count = 1, neighb = 0;
	unordered_set<string> visited;
	queue<string> level;
	level.push(start);
	visited.insert(start);
	while(!level.empty())
	{
	    string curr = level.front();
	    level.pop();
	    --count;
	    for(int i = 0; i < curr.size(); ++i)
	    {
		for(int j = 0; j < 26; ++j)
		{
		    string next = curr;
		    next[i] = 'a' + j;
		    if(next == end)
			return length;
		    if(dict.find(next) != dict.end() && visited.find(next) == visited.end())
		    {
			++neighb;
			level.push(next);
			visited.insert(next);
		    }
		}
	    }
	    if(count == 0)  // new level starts
	    {
		++length;
		count = neighb;
		neighb = 0;
	    }
	}
	return 0;
    }
};

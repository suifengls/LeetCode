/*
  Given a collection of intervals, merge all overlapping intervals.
  
  For example,
  Given [1,3],[2,6],[8,10],[15,18],
  return [1,6],[8,10],[15,18].

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
	if(intervals.size() <= 1)
	    return intervals;
	vector<Interval> result;
	sort(intervals.begin(), intervals.end(), Solution::cmp);
	result.push_back(intervals[0]);
	for(int i = 1; i < intervals.size(); ++i)
	{
	    if(result.back().end < intervals[i].start)
		result.push_back(intervals[i]);
	    else
		result.back().end = max(result.back().end, intervals[i].end);
	}
	return result;
    }
    static bool cmp(Interval it1, Interval it2)
    {
	return it1.start < it2.start;
    }
};

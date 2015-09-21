/*
	
Given a non-overlapping interval list which is sorted by start point.

Insert a new interval into it, make sure the list is still in order and non-overlapping (merge intervals if necessary).

Have you met this question in a real interview? Yes
Example
Insert [2, 5] into [[1,2], [5,9]], we get [[1,9]].

Insert [3, 4] into [[1,2], [5,9]], we get [[1,2], [3,4], [5,9]].
	
*/

#include "../commonHeader.h"

class Interval 
{
public:
	
	int start, end;
	Interval(int start, int end) 
	{
    	this->start = start;
		this->end = end;
	}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
{
	vector<Interval> ret;
	
	int p = 0;
	int q = 0;
	int c = 1;
	while(p < intervals.size() && q < c)
	{
		if(intervals[p].start <= newInterval.start)
		{
			ret.push_back(intervals[p++]);
		}
		else
		{
			ret.push_back(newInterval);
			q++;
		}
	}
	
	while(p < intervals.size())
	{
		ret.push_back(intervals[p++]);
	}
	
	while(q < c)
	{
		ret.push_back(newInterval);
		q++;
	}
	
	//merge
	for(int i = 0; i + 1 < ret.size();)
	{
		if(ret[i].end < ret[i + 1].start)
		{
			i++;
		}
		else
		{
			ret[i].start = std::min(ret[i].start,ret[i + 1].start);
			ret[i].end = std::max(ret[i].end,ret[i + 1].end);
			ret.erase(ret.begin() + i + 1);
		}
	}
	
	return ret;
}

vector<Interval> insertI(vector<Interval> &intervals, Interval newInterval)
{
	
}

int main()
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1,5));
	Interval newInterval(2,3);
	vector<Interval> ret = insert(intervals,newInterval);
	for(auto i : ret)
	{
		cout << i.start << " " << i.end << endl;
	}
	cout << endl;
}
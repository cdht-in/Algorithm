/*
  Given a collection of intervals, merge all overlapping intervals.
  For example,
  Given [1,3],[2,6],[8,10],[15,18],
  return [1,6],[8,10],[15,18].

*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start (0), end (0) {}
  Interval (int s, int e) : start (s), end (e) {}
};

/*
first implementation

int Compare(const Interval& a, const Interval& b){
  return a.start < b.start;
}

void PrintVector(const vector<Interval>& vec){
  for(int i = 0; i < vec.size(); i++){
    cout << "[ " << vec[i].start << "," << vec[i].end << " ]" << endl;
  }
}

vector<Interval> merge(vector<Interval> &intervals) {
  if(intervals.size() <= 1)
    return intervals;
  //sort first in terms of left boudary
  sort(intervals.begin(),intervals.end(),Compare);
  vector<Interval> ret;
  int laststart = intervals[0].start;
  int lastend = intervals[0].end;
  for(int i = 1; i < intervals.size(); i++){
    //overlapped
    if(intervals[i].start  <= lastend && intervals[i].end > lastend ){
      lastend = intervals[i].end;
    }
    //contained
    else if(intervals[i].start <= lastend && intervals[i].end <= lastend){
      continue;
    }
    //disjointed
    else{
      ret.push_back(Interval(laststart,lastend));
      //update info
      laststart = intervals[i].start;
      lastend = intervals[i].end;
    }
  }
  ret.push_back(Interval(laststart,lastend));
  return ret;
}

*/

//second implementation

int Compare(const Interval& a, const Interval& b){
  return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &intervals) {
	vector<Interval> result;
	if(intervals.size() < 1)
	{
		return result;
	}
	if(intervals.size() == 1)
	{
		result.push_back(intervals[0]);
		return result;
	}
	
	sort(intervals.begin(),intervals.end(),Compare);
	
	result.push_back(intervals[0]);
	for(int i = 1; i < intervals.size(); i++)
	{
		Interval top = result.back();
		result.pop_back();
		
		if(top.end < intervals[i].start)
		{
			result.push_back(top);
			result.push_back(intervals[i]);
		}
		else{
			int start = (top.start <= intervals[i].start) ? top.start : intervals[i].start;
			int end = (top.end >= intervals[i].end) ? top.end : intervals[i].end;
			result.push_back(Interval(start,end));
		}
	}
	return result;
}


int main()
{
  Interval a(1,3);
  Interval b(2,6);
  Interval c(8,10);
  Interval d(15,18);
  vector<Interval> vec;
  vec.push_back(a);
  vec.push_back(b);
  vec.push_back(c);
  vec.push_back(d);
  vec = merge(vec);
  PrintVector(vec);
}

/*  Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

  You may assume that the intervals were initially sorted according to their start times.

  Example 1:
  Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

  Example 2:
  Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

  This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

*/
#include <vector>
#include <iostream>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start (0), end (0) {}
  Interval (int s, int e) : start (s), end (e) {}
};

/*

first implementation

int Bisearch (vector<Interval>& intervals, int start)
{
  int l = 0;
  int r = intervals.size() - 1;
  int mid = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (intervals[mid].start == start) {
      return mid;
    }
    else if (intervals[mid].start < start) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return l;
}

void merge (vector<Interval>& intervals, int p)
{
  Interval intertmp = intervals[p];
  for (int i = 0; i < intervals.size(); i++) 
    cout << intervals[i].start << " " << intervals[i].end << endl;
  cout << "p size " << p << " " << intervals.size() << endl;
  while ( (p < intervals.size() - 1) && (intertmp.end >= intervals[p + 1].start) ) {
      int end = (intertmp.end <= intervals[p + 1].end) ? intervals[p + 1].end : intertmp.end;
      intertmp = Interval (intertmp.start, end);
      intervals.insert (intervals.begin() + p, intertmp);
      //watch out for the vector shrinking
      intervals.erase (intervals.begin() + p + 1);
      intervals.erase (intervals.begin() + p + 1);
      for (int i = 0; i < intervals.size(); i++) {
        cout << interv	als[i].start << " " << intervals[i].end << endl;
      }
    }
  }
  vector<Interval> insert (vector<Interval>& intervals, Interval newInterval) {
    if (intervals.size() < 1) {
      intervals.push_back (newInterval);
      return intervals;
    }
    int p = Bisearch (intervals, newInterval.start);
    cout << "p is " << p << endl;
    if (intervals[p].start != newInterval.start && intervals[p].end != newInterval.end)
      intervals.insert (intervals.begin() + p, newInterval);
    merge (intervals, p);
    return intervals;
  }

*/

int binarySearch(vector<Interval> &intervals, Interval newInterval) {
	int l = 0;
	int r = intervals.size() - 1;
	int mid = 0;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(intervals[mid].start == newInterval.start)
			return mid;
		else if(intervals[mid].start < newInterval.start)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	//l is the insertion point;
	return l;
}

//second implementation
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval> result;  
	result.push_back(newInterval);  
	for(int i=0; i< intervals.size(); i++)  
	{  
	  Interval newInt = result.back();  
	  result.pop_back();  
	   Interval* cur = &intervals[i];
	   
	   //cotained
	   if(cur->end < newInt.start)  
	   {  
	     result.push_back(*cur);  
	     result.push_back(newInt);          
	   }
	   //not overlapped        
	   else if(cur->start > newInt.end)  
	   {  
	     result.push_back(newInt);  
	     result.push_back(*cur);          
	   }  
	   else  
	   {          
	     newInt.start = min(cur->start, newInt.start);  
	     newInt.end = max(cur->end, newInt.end);  
	     result.push_back(newInt);  
	   }  
	 }  
	 return result;
}


int main() {
	 
    Interval a (1, 5);
    vector<Interval> vec;
    vec.push_back (a);
    Interval c (2, 7);
    vector<Interval> ret = insert (vec, c);
    cout << " final :" << endl;
    for (int i = 0; i < ret.size(); i++) {
      cout << ret[i].start << " " << ret[i].end << endl;
    }

  }

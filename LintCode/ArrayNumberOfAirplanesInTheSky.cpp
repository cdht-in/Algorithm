/*
	
Given an interval list which are flying and landing time of the flight. How many airplanes are on the sky at most?

Have you met this question in a real interview? Yes
Example
For interval list [[1,10],[2,3],[5,8],[4,7]], return 3

Note
If landing and flying happens at the same time, we consider landing should happen at first.
	
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

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  
  bool operator() (const Interval& lhs, const Interval&rhs) const
  {
    if (reverse) return (lhs.end>rhs.end);
    else return (lhs.end<rhs.end);
  }
};

bool myfunction (Interval i,Interval j) { return (i.start<j.start); }

//sweep line
int countOfAirplanes(vector<Interval> &airplanes) 
{
	//sorted by start time
	sort(airplanes.begin(),airplanes.end(),myfunction);
	
	//minHeap
	priority_queue<Interval,vector<Interval>,mycomparison> q(mycomparison(true));
	
	int max = 0;
	for(int i = 0; i < airplanes.size(); i++)
	{
		if(q.empty() || airplanes[i].start < q.top().end)
		{
			q.push(airplanes[i]);
		}
		else
		{
			while(q.empty() == false && q.top().end <= airplanes[i].start)
			{
				q.pop();
			}
			
			q.push(airplanes[i]);
		}
		
		max = std::max(max,(int)q.size());
	}
	return max;
}

int main()
{
	vector<Interval> intervals = {Interval(1,2),Interval(2,3)};
	cout << countOfAirplanes(intervals) << endl;
}
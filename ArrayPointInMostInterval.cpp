/*

Question: Write a function that, given n integer intervals [a_i, b_i] on the real axes, where the absolute value of the coordinates is bounded by M, returns a point that belongs to the maximum number of intervals. Point x belongs to the interval [a, b] iff a <= x <= b.

Example:
intervals: [-4, -1] [3, 5] [-5, -3] [-2, 3] [0, 4]
output: 3 

                      -----------------
          ---------          -------------
              -------------           -------
-M  ...  -5  -4  -3  -2  -1  0  1  2  3  4  5  ...  M
	
	
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Interval{
	int start;
	int end;
	
	Interval(int start, int end):start(start),end(end){}
};

//brute force O(n^2)
int points(vector<Interval>& vec){
    
  int point = 0;
  int max = 0;
  for(int i = 0; i < vec.size(); i++)
  {
    int submax = 1;
	
    for(int j = 0; j < vec.size(); j++)
    {
      if(vec[i].end >= vec[j].start && vec[i].end <= vec[j].end)
      {
			submax++;
	  }
    }
    
    if(submax > max)
	{
      point = vec[i].end;
      max = submax;
    }
  }
  
  return point;
}


int func(Interval i1, Interval i2)
{
 return i1.start < i2.start; 
}

//sort it first
int pointsI(vector<Interval>& vec){
    
  sort(vec.begin(),vec.end(),func);
  
  int point = 0;
  int max = 0;
  
  for(int i = 0; i < vec.size(); i++)
  {
    int submax = 1;
	
    for(int j = i + 1; j < vec.size(); j++)
    {
      if(vec[i].end >= vec[j].start && vec[i].end <= vec[j].end)
      {
			submax++;
	  }
    }
    
    if(submax > max)
	{
      point = vec[i].end;
      max = submax;
    }
  }
 
  return point;
}





int main()
{
	vector<Interval> intervals;
	intervals.push_back(Interval(-4,-1));
	intervals.push_back(Interval(3,5));
	intervals.push_back(Interval(-5,-3));
	intervals.push_back(Interval(-2,3));
	intervals.push_back(Interval(0,4));
	
	cout << pointsI(intervals) << endl;
}
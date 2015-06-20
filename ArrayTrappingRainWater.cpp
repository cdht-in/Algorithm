/*
  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

  For example,
  Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include <stack>
#include <iostream>
#include <vector>

using namespace std;


/*
first implementation

int trap (int A[], int n)
{
  //no way to contain any water
  if (n <= 2) return 0;
  //1. first run to calculate the heiest bar on the left of each bar
  int* lmh = new int[n];//for the most height on the left
  lmh[0] = 0;
  int maxh = A[0];
  for (int i = 1; i < n; ++i) {
    lmh[i] = maxh;
    if (maxh < A[i]) maxh = A[i];
  }
  int trapped = 0;
  //2. second run from right to left,
  // caculate the highest bar on the right of each bar
  // and calculate the trapped water simutaniously
  maxh = A[n - 1];
  for (int i = n - 2; i > 0; --i) {
    int left = lmh[i];
    int right = maxh;
    int container = min (left, right);
    if (container > A[i]) {
      trapped += container - A[i];
    }
    if (maxh < A[i]) maxh = A[i];
  }
  delete lmh;
  return trapped;
}

*/

//second implementation

int trap(int A[], int n) {
	if(n <= 2)
		return 0;
	int sum = 0;
	
	stack<int> lst;
	lst.push(A[0]);
	
	int trapped = 0;
	//left height is the dominating boundary
	for(int i = 0; i < n; i++)
	{
		//think as if the stack top is moving with i
		if(A[i] <= lst.top())
		{
			trapped += (lst.top() - A[i]) * 1;
		}
		//cause computing the previous trapped water
		else
		{
			sum += trapped;
			trapped = 0;
			lst.push(A[i]);		
		}
	}
	
	trapped = 0;
	stack<int> rst;
	rst.push(A[n - 1]);
	
	//right height is the dominating boundary
	for(int i = n - 1; i >= 0; i--)
	{
		//think as if the stack top is moving with i
		//NOTE here if A[i] <= rst.top() would cause the value to be doubled in case like [2,0,2]
		if(A[i] < rst.top())
		{
			trapped += (rst.top() - A[i]) * 1;
		}
		//cause computing the previous trapped water
		else
		{
			sum += trapped;
			trapped = 0;
			rst.push(A[i]);		
		}
	}
	
	return sum;
}








































//second implementation, O(2n) in time and O(n) in space
int trapI(int A[], int n) 
{
	if(n <= 2)
		return 0;
	vector<int> lMax(n,0);
	
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		lMax[i] = max;	
		max = std::max(A[i],max);
	}
	
	max = 0;
	int area = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		max = std::max(A[i],max);
		
		int lowerBound = std::min(max,lMax[i]);
		
		//compute the capacity for each bar
		if(lowerBound - A[i] > 0)
			area += lowerBound - A[i];
	}
	
	return area;
}

//third implementation
int trapII(int A[], int n)
{
	if(n <= 2)
		return 0;
	
	int l = 0;
	int r = n - 1;
	int area = 0;
	while(l < r)
	{
		if(A[l] < A[r])
		{
			int min = A[l];
			l++;
			//NOTE this would break only when the A[l] > min or l == r => A[r] > A[l]
			while(l < r && A[l] < min)
			{
				area += min - A[l];
				l++;
			}
		}
		else
		{
			int min = A[r];
			r--;
			//NOTE this would break only when the A[l] > min or l == r => A[r] > A[l]
			while(l < r && A[r] < min)
			{
				area += min - A[r];
				r--;
			}
		
		}
	}
	return area;
}	 




int main()
{
	int foo[] = {4,2,3};
	cout << trapI(foo,sizeof(foo) / sizeof(int)) << endl;
}

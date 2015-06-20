/*
  Given an array of non-negative integers, you are initially positioned at the first index of the array.

  Each element in the array represents your maximum jump length at that position.

  Your goal is to reach the last index in the minimum number of jumps.

  For example:
  Given array A = [2,3,1,1,4]

  The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/


#include <iostream>
#include <climits>

using namespace std;

/*

first implementation

void jumpHelper (int A[], int p, int n, int s, int& min)
{
  if (p == n - 1) {
    min = (s < min) ? s : min;
    return;
  }
  else if (p > n - 1)
    return;
  for (int i = 1; i <= A[p]; i++) {
    jumpHelper (A, p + i, n, s + 1, min);
  }
}

//brute froce approach
int jumpI (int A[], int n)
{
  //if can reach the end, at most n + 1 steps, e.g. array with all 1s
  if (n < 1)
    return -1;
  int min = n + 1;
  jumpHelper (A, 0, n, 0, min);
  //if can't reach the end
  if (min == n + 1)
    return -1;
  return min;
}

//O(n) DP problem
int jump(int A[], int n){
  int s = 0;
  if(n <= 1)
    return s;
  //at least 2
  int dest = n - 1;
  int p = 0;
  while(1){
    int tmp = -1;
    //find the first one that can jump to the dest
    for(p = dest - 1; p >= 0; p--)
      {
	//if can reach in one jump
	if(A[p] >= (dest - p))
	  tmp = p;
      }
    s++;
    dest = tmp;
    if(dest == 0)
      return s;
    //cant reach the end
    else if(dest < 0)
      return -1;
  }
}

*/

//second implementation
int jump(int A[], int n) {
	if(n == 1)
		return 0;
	
	int start = 0;
	int end = 0;
	int c = 0;
	//greedy approach,find the maximum jump length, if it can reach the end, this would result in the minimum number of jumps
	while(end < n)
	{
		int max = start;
		c++;
		for(int i = start; i <= end; i++)
		{
			if(i + A[i] >= n - 1)
			{
				return c;
			}
			if(i + A[i] > max)
				max = i + A[i];
		}
		
		//didn't move forward
		if(max == start)
		{
			//can't reach the end
			return -1;
		}
		
		start = end + 1;
		end = max;
	}
	
	return c;
}

int main()
{
  int foo[] = {1,0,2};
  int n = sizeof(foo) / sizeof(int);
  cout << jump(foo,n) << endl;
}

/*
  Given an array of non-negative integers, you are initially positioned at the first index of the array.

  Each element in the array represents your maximum jump length at that position.

  Determine if you are able to reach the last index.

  For example:
  A = [2,3,1,1,4], return true.

  A = [3,2,1,0,4], return false.
*/
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/*
first implementation

//recursive O(2^n)
int JumpGame (int* a, int i, int n)
{
  if (n <= 1 || i == n - 1)
    return 1;
  if (i > n - 1 || !a[i])
    return 0;
  int j;
  for (j = 1; j <= a[i]; j++) {
    if (JumpGame (a, i + j, n) )
      return 1;
  }
  return 0;
}

bool canJumpHelper (int A[], int n, int p)
{
  if(A[p] + p >= n - 1)
    return true;
  for (int i = A[p]; i >= 0; i--) {
    if (canJumpHelper (A, n, p + i) )
      return true;
  }
  return false;
}

//naive approach,try out all the possibilities
bool canJumpI (int A[], int n)
{
  if (n < 2)
    return true;
  return canJumpHelper (A, n, 0);
}

//BFS
bool canJumpII (int A[], int n){
  if(n < 2)
    return true;
  queue<int> dest;
  dest.push(n - 1);
  while(!dest.empty()){
    int p = dest.front();
    dest.pop();
    //reach the beginning
    if(p == 0)
      return true;
    for(int i = p - 1; i >= 0; i--)
      {
	if(i + A[i] >= p)
	  dest.push(i);
      }
  }
  return false;
}

bool canJump (int A[], int n){
  if(n < 2)
    return true;
  int dest = n - 1;
  while(1){
    int tmpdest = -1;
    for(int i = dest - 1; i >= 0; i--){
      if(i + A[i] >= dest)
	tmpdest = i;
    }
    //can't reach the end
    if(tmpdest == -1)
      return false;
    //reach the end
    if(tmpdest == 0)
      return true;
    dest = tmpdest;
  }
}

*/

//second implementation
bool canJump(int A[], int n) {	
	
	int maxStepCover = 0;
	for(int i = 0; i <= maxStepCover && i < n; i++)
	{
		if(A[i] + i > maxStepCover)
			maxStepCover = A[i] + i;
		if(maxStepCover >= n - 1)
			return true;
	}
	return false;
}

//DP
bool canJump(int A[], int n) {	
	int jump[n];
    jump[0] = 0;  
    for(int i=1; i < n; i++)  
    {  
	  //定义 jump[i]为从index 0 走到第i步时，剩余的最大步数。
      jump[i] = max(jump[i - 1], A[i - 1]) -1;  
      if(jump[i] < 0)  
         return false;;  
     }  
     return jump[n-1] >= 0;  
}


int main()
{
  int foo[] = {2,3};
  int n = sizeof(foo) / sizeof(int);
  cout << canJump(foo,n) << endl;
  
}

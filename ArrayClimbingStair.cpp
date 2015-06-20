/*
  You are climbing a stair case. It takes n steps to reach to the top.
  Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/


#include <cstdio>
#include <iostream>

using namespace std;

/*
first implementation

int nWays (int s)
{
  if (s == 1)
    return 1;
  if (s == 2)
    return 2;
  int fn1 = 2;
  int fn2 = 1;
  int fn = 0;
  for (int i = 3; i <= s; i++) {
    //the number of ways to climb i is the sum of number of ways to climb i - 1 and i - 2
    fn = fn1 + fn2;
    //the current i - 1 steps will be i - 2 for the next run
    fn2 = fn1;
    //the current i steps will be the i - 1 for the next run
    fn1 = fn;
    cout << fn1 << " " << fn2 << endl;
  }
  return fn;
}

*/

//second implementation

int climbStairs(int n) {
	if(n == 0 || n == 1)
		return 1;
	if(n == 2)
		return 2;
	int OneStepBefore = 2;
	int TwoStepBefore = 1;
	int nSteps = 0;
	for(int i = 3; i <= n; i++)
	{
		nSteps = OneStepBefore + TwoStepBefore;
		TwoStepBefore = OneStepBefore;
		OneStepBefore = nSteps;
		
	}
	return nSteps;
}

int climbStairsI(int n) {
	//only need two previous steps
	int dp[3];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
 	for(int i = 3; i <= n; i++)
	{
		//f(n) = f(n - 1) + f(n - 2)
		dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3]; 
	}
	return dp[n % 3];
}










































//third implementation
int climbStairsII(int n)
{
	if(n < 1)
		return 0;
	
	int steps[3];
	steps[0] = 1;
	steps[1] = 2;
	for(int i = 2; i < n; i++)
	{
		steps[i % 3] = steps[(i - 1) % 3] + steps[(i - 2) % 3];
	}
	return steps[(n - 1) % 3];
}



int main()
{
	int n = 10;
	cout << climbStairs(n) << " " << climbStairsI(n) << endl;
}

/*
	Write a method to generate the nth Fibonacci number.
*/
#include <vector>
#include <iostream>

using namespace std;

int fib(int n)
{
	int dp[3];
	dp[0] = 1;
	dp[1] = 1;
	
	for(int i = 2; i <= n - 1; i++)
	{
		dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];
	}
	
	return dp[(n - 1) % 3];
}

int main()
{
	cout << fib(5) << endl;
}
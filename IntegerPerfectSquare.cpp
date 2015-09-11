/*
	
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
	
*/

#include "./commonHeader.h"

//this greedy approach wouldn't work for 12, it would return 4 instead of 4
// of 3, wrong: 12 = 9 + 1 + 1 + 1, right: 4 + 4 + 4
int numSquares(int n) 
{
	if(n == 0 || n == 1)
		return n;
	
	int l = 1, r = n,mid = 0;
	while(l <= r)
	{
		mid = l + (r - l) / 2;
		if(mid * mid > n)
		{
			r = mid - 1;
		}
		else if(mid * mid < n)
		{
			l = mid + 1;
		}
		else
		{
			return 1 + numSquares(n - mid * mid);
		}
	}
	//r is the biggest number that r * r is less than n 
	return 1 + numSquares(n - r * r);
}

//wouldn't work
int numSquaresI(int n)
{
	vector<int> dp(n + 1,INT_MAX);
	dp[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		int l = 1, r = i, mid = 0;
		while(l <= r)
		{
			mid = l + (r - l) / 2;
			if(mid * mid > i)
			{
				r = mid - 1;
			}
			else if(mid * mid < i)
			{
				l = mid + 1;
			}
			else
			{
				dp[i] = 1;
				break;
			}
		}
		int min = std::min(dp[i - r * r], dp[i - (r - 1) * (r - 1)]);
		dp[i] = std::min(dp[i], 1 + min);
	}
	return dp[n];
}

int numSquaresII(int n) 
{
    static vector<int> dp {0};
    while (dp.size() <= n) 
	{
        int m = dp.size(), squares = INT_MAX;
        for (int i = 1; i * i <= m; ++i)
		{
        	squares = min(squares, dp[m - i * i] + 1);
        }
        dp.push_back(squares);
    }
    return dp[n];
}

int numSquaresIII(int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
	{
        int squares = INT_MAX;
        for (int j = 1; j * j <= i; ++j)
		{
        	squares = std::min(squares, dp[i - j * j] + 1);
        }
        dp[i] = squares;
    }
    return dp[n];
}

int main()
{
	int n = 6;
	cout << numSquaresIII(n) << endl;
}
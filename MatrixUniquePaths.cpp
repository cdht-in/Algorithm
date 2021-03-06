/*
	
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/

#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
		if(m == 0 || n == 0)
			return 0;
	
		vector<vector<int> > dp(m, vector<int> (n, 0));
		
		for(int i = 0; i < n; i++)
		{
			dp[0][i] = 1;
		}
	
		for(int i = 0; i < m; i++)
		{
			dp[i][0] = 1;
		}

		for(int i = 1; i < m; i++)
		{
			for(int j = 1; j < n; j++)
			{
				int fromTop = dp[i - 1][j];
				int fromLeft = dp[i][j - 1];
				dp[i][j] = fromTop + fromLeft;
			}
		}
			
		return dp[m - 1][n - 1];
}








































int uniquePathsI(int m, int n) 
{
	vector<vector<int> > dp(m, vector<int>(n,0));
	for(int i = 0; i < m; i++)
		dp[i][0] = 1;
	
	for(int i = 0; i < n; i++)
		dp[0][i] = 1;
	
	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			dp[i][j] = dp[i - 1][j]  + dp[i][j - 1];
		}
	}
	
	return dp[m - 1][n - 1];
}


int main()
{
		
}
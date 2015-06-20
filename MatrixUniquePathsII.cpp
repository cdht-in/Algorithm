/*

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
	
*/

#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
		return 0;
	
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	
	if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
		return 0;
	
	vector<vector<int> > dp(m, vector<int> (n, 0));
	
	for(int i = 0; i < n; i++)
	{
		if(obstacleGrid[0][i] == 0)
			dp[0][i] = 1;
		else
		{
			while(i < n){
				dp[0][i++] = -1;				
			}
		}
	}

	for(int i = 0; i < m; i++)
	{
		if(obstacleGrid[i][0] == 0)
			dp[i][0] = 1;
		else
		{
			while(i < m){
				dp[i++][0] = -1;				
			}			
		}
	}

	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if(obstacleGrid[i][j] == 1){
				dp[i][j] = -1;
				continue;
			}
			
			int fromTop = dp[i - 1][j];
			int fromLeft = dp[i][j - 1];
			
			if(fromTop == -1 && fromLeft == -1)
				dp[i][j] = -1;
			else if(fromTop != -1 && fromLeft != -1)
				dp[i][j] = fromTop + fromLeft;
			else
				dp[i][j] = (fromTop != -1)? fromTop : fromLeft;
		}
	}
	if(dp[m - 1][n - 1] == -1)
		return 0;	
	return dp[m - 1][n - 1];
}

int main()
{
	
}
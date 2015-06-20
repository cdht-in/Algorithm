/*
	
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

/*
first implementation

//DFS
void minPathSumHelper(vector<vector<int> > &grid, int m, int n, int i, int j,vector<bool>& visited, int& min, int distant) {
	if(i == m && j == n)
	{
		distant += grid[i][j];
		min = (min < distant)? min : distant;
		return;
	}
	
	int pos = i * n + j;
	distant += grid[i][j];
	if(i + 1 <= m && visited[pos] == false)
	{
		visited[pos] = true;
		minPathSumHelper(grid,m,n,i + 1,j,visited,min,distant);
		visited[pos] = false;
	}
	
	if(j + 1 <= n && visited[pos] == false)
	{
		visited[pos] = true;
		minPathSumHelper(grid,m,n,i,j + 1,visited,min,distant);
		visited[pos] = false;		
	}
}


int minPathSum(vector<vector<int> > &grid) {
	if(grid.size() == 0 || grid[0].size() == 0)
		return 0;
	int m = grid.size() - 1;
	int n = grid[0].size() - 1;
	int min = INT_MAX;
	vector<bool> visited((m + 1) * (n + 1), false);
	minPathSumHelper(grid,m,n,0,0,visited,min,0);
	return min;
}
*/

int minPathSum(vector<vector<int> > &grid) {
	if(grid.size() == 0 || grid[0].size() == 0)
		return 0;
	int m = grid.size();
	int n = grid[0].size();
	
	vector<vector<int> > dp(m, vector<int> (n, 0));
	
	dp[0][0] = grid[0][0];
	
	for(int i = 1; i < n; i++)
	{
		dp[0][i] = dp[0][i - 1] + grid[0][i];
	}
	
	for(int i = 1; i < m; i++)
	{
		dp[i][0] = dp[i - 1][0] +  grid[i][0];
	}

	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			int fromTop = dp[i - 1][j];
			int fromLeft = dp[i][j - 1];
			dp[i][j] = (fromTop < fromLeft)? fromTop : fromLeft;
			dp[i][j] += grid[i][j];
		}
	}
			
	return dp[m - 1][n - 1];
}

int main(){
	
	vector<vector<int> > grid(2,vector<int>(2,0));
	grid[0][0] = 1;
	grid[0][1] = 2;
	grid[1][0] = 1;
	grid[1][1] = 3;
	
	cout << minPathSum(grid) << endl;
	
		
	
}
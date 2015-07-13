
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

vector<int> ReverseFibo(int a, int b)
{
	assert(b > 0);
	assert(a >= b);
	
	int size = 3;
	int dp[size];
	dp[0] = a;
	dp[1] = b;
	vector<int> ret;
	ret.push_back(a);
	ret.push_back(b);
	int i = 2;
	int next,prev1,prev2;
	while(1)
	{
		next = i % size;
		prev2 = (i - 2) % size;
		prev1 = (i - 1) % size;
		dp[next] = dp[prev2] - dp[prev1];
		ret.push_back(dp[next]);
		
		//cout << dp[next] << endl;
		if(dp[next] <= 0)
			break;
		dp[prev2] = dp[prev1];
		i++;
	}
	return ret;
}

bool NextGeneration(vector<vector<bool> > & grid)
{
	assert(grid.size() > 0);
	assert(grid[0].size() > 0);
	int m = grid.size();
	int n = grid[0].size();
	
	vector<vector<bool> > tempGrid(m,vector<bool>(n,false));
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			tempGrid[i][j] = grid[i][j];
		}
	}
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int liveCount = 0;
			//clockwise check
			if(i - 1 >= 0 && j - 1 >= 0)
				liveCount += (grid[i - 1][j - 1])? 1 : 0;
			if(i - 1 >= 0)
				liveCount += (grid[i - 1][j])? 1 : 0;
			if(i - 1 >= 0 && j + 1 < n)
				liveCount += (grid[i - 1][j + 1])? 1 : 0;
			if(j + 1 < n)
				liveCount += (grid[i][j + 1])? 1 : 0;
			if(i + 1 < m && j + 1 < n)
				liveCount += (grid[i + 1][j + 1])? 1 : 0;
			if(i + 1 < m)
				liveCount += (grid[i + 1][j])? 1 : 0;
			if(i + 1 < m && j - 1 >= 0)
				liveCount += (grid[i + 1][j - 1])? 1 : 0;
			if(j - 1 >= 0)
				liveCount += (grid[i][j - 1])? 1 : 0;
			
			if(liveCount < 2 || liveCount > 3)
				tempGrid[i][j] = false;
			if(liveCount == 2)
				tempGrid[i][j] = grid[i][j];
			if(liveCount == 3)
				tempGrid[i][j] = true;
		}
	}
	
	bool alive = false;
	//copy the temp grid back
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			grid[i][j] = tempGrid[i][j];
			if(grid[i][j])
				alive = true;
		}
	}
	
	return alive;
}

int main()
{
	vector<int> ret = ReverseFibo(10,1);
	for(int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << endl;
	}
}
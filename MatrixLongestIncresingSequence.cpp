/*

Longest Increasing Sequence 2D matrix 二维数组最长递增子序列，只能上下左右，
不能对角线，找出长度或者移动路径，这个怎么做？brutal force?

*/

#include <vector>
#include <iostream>

using namespace std;

void Update(vector<vector<int> >& mat, vector<vector<int> >& dp, int i, int j)
{
	int m = mat.size();
	int n = mat[0].size();	
}

int LongestIncreasingSequence(vector<vector<int> >& mat)
{
	
}

/*
int LongestIncreasingSequenceI(vector<vector<int> >& mat)
{
	int m = mat.size();
	int n = mat[0].size();
	vector<vector<int> > dp(m,vector<int>(n,1));
	
	//longest sequence from top and left
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i - 1 >= 0 && mat[i][j] > mat[i - 1][j])
			{
				dp[i][j] = std::max(dp[i][j],dp[i - 1][j] + 1);
			}
		
			if(j - 1 >= 0 && mat[i][j] > mat[i][j - 1])
			{
				dp[i][j] = std::max(dp[i][j],dp[i][j - 1] + 1);
			}
		}
	}
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	
	for(int i = m - 1; i >= 0; i--)
	{
		for(int j = n - 1; j >= 0; j--)
		{
			if(i + 1 < m && mat[i][j] > mat[i + 1][j])
			{
				dp[i][j] = std::max(dp[i][j],dp[i + 1][j] + 1);
			}
	
			if(j + 1 < n && mat[i][j] > mat[i][j + 1])
			{
				dp[i][j] = std::max(dp[i][j],dp[i][j + 1] + 1);
			}				
		}
	}
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	int max = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
			if(dp[i][j] > max)
			{
				max = dp[i][j];
			}
		}
		cout << endl;
	}
	return max;
}
*/

int main()
{
	vector<vector<int> > mat;
	mat.push_back(vector<int>({1,3,4}));
	mat.push_back(vector<int>({6,5,2}));
	mat.push_back(vector<int>({8,9,2}));
	
	cout << LongestIncreasingSequence(mat) << endl;
}
/*
	
Give you an integer matrix (with row size n, column size m)，find the longest increasing continuous subsequence in this matrix. (The definition of the longest increasing continuous subsequence here can start at any row or column and go up/down/right/left any direction).

Have you met this question in a real interview? Yes
Example
Given a matrix:

[
  [1 ,2 ,3 ,4 ,5],
  [16,17,24,23,6],
  [15,18,25,22,7],
  [14,19,20,21,8],
  [13,12,11,10,9]
]
return 25

Challenge
O(nm) time and memory.
	
*/

#include "../commonHeader.h"


//update the longest increasing sequence to (i,j)
int dfs(int i, int j, int maxRow, int maxCol,
         const vector<vector<int>> &A,
         vector<vector<int>> &dp) 
{
    // 记忆化搜索，如果有值(之前dfs已经计算出的)直接返回，不再计算 
    if (dp[i][j] != 0) 
	{
        return dp[i][j];
    }
     
    // 从up开始逆时针
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {-1, 0, 1, 0};
     
    // dfs更新dp状态
    for (int ix = 0; ix < 4; ix++) 
	{
        int x = i + dx[ix];
        int y = j + dy[ix];
		
        if (0 <= x && x < maxRow && 0 <= y && y < maxCol && A[i][j] < A[x][y]) 
		{
			dp[i][j] = max(dp[i][j], dfs(x, y, maxRow, maxCol, A, dp));
        } 
    }
     
    return ++dp[i][j];
}

int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) 
{
	if (A.empty() || A[0].empty()) 
	{
		return 0;
	} 
         
	int ret = 0;
	int maxRow = A.size();
	int maxCol = A[0].size();
	vector<vector<int>> dp(maxRow, vector<int>(maxCol));
	for (int i = 0; i < maxRow; i++) 
	{
	    for (int j = 0; j < maxCol; j++) 
		{
	        ret = max(ret, dfs(i, j, maxRow, maxCol, A, dp));
	    }
	}
            	
	return ret;
	
}

int main()
{
	
}
/*
  Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

  For example, given the following triangle
  [
  [2],
  [3,4],
  [6,5,7],
  [4,1,8,3]
  ]
  The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

  Note:
  Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

#include <climits>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

//O(n^2) in time and O(n^2) in space, first implementation
int minimumTotal (vector<vector<int> >& triangle)
{
  int sum = 0;
  if (triangle.size() < 1 || triangle[0].size() < 1)
    return sum;
  int row = triangle.size();
  int col = triangle[row - 1].size();
  vector<vector<int> > mat (row, vector<int> (col, 0) );
  mat[0][0] = triangle[0][0];
  for (int i = 1; i < row; i++) {
    for (int j = 0; j < triangle[i].size(); j++) {
      int min = 0;
      if (j < triangle[i - 1].size() )
        min = mat[i - 1][j];
      else
        min = INT_MAX;
      if (j - 1 >= 0)
        min = (min < mat[i - 1][j - 1]) ? min : mat[i - 1][j - 1];
      mat[i][j] = min +  triangle[i][j];
    }
  }
  sum = mat[row - 1][0];
  for (int i = 1; i < col; i++) {
    sum = (sum < mat[row - 1][i]) ? sum : mat[row - 1][i];
  }
  return sum;
}

//second implementation, one dimension DP
int minimumTotalI(vector<vector<int> > &triangle) {
	if(triangle.size() == 0)
		return 0;
	int nRow = triangle.size() - 1;
	int LastRowCol = triangle[nRow].size();
	vector<int> min(LastRowCol);
		
	//start from last row
	for(int i = nRow; i >= 0; i--)
	{
		int col = triangle[i].size();
		
		for(int j = 0; j < col; j++)
		{
			//last row 
			if(i == nRow)
			{
				min[j] = triangle[i][j];
				continue;
			}
			
			//THIS IS BRILLIANT!
			min[j] = std::min(min[j],min[j + 1]) + triangle[i][j];
		}
	}
	return min[0];
}








































//third implementation
int minimumTotalII(vector<vector<int> > &triangle) 
{
 	if(triangle.size() == 0)
		return 0;
	
	int row = triangle.size();
	
	vector<vector<int> > dp(row,vector<int>(row, 0));
	dp[0][0] = triangle[0][0];
	
	for(int i = 1; i < row; i++)
	{	
		int col = triangle[i].size();
		for(int j = 0; j < col; j++)
		{
			if(j == 0)
			{
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if(j == col - 1)
			{
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else
			{
				int min = (dp[i - 1][j] <  dp[i - 1][j - 1])? dp[i - 1][j] : dp[i - 1][j - 1];
				dp[i][j] = min + triangle[i][j];
			}
		}
	}
	
	/*
	for(int i = 0; i < dp.size(); i++)
	{
		for(int j = 0; j < dp[i].size(); j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	//find the min in the last row
	int min = dp[row - 1][0];
	for(int i = 1; i < row; i++)
	{
		if(dp[row - 1][i] < min)
			min = dp[row - 1][i];
	}
	return min;	
}




int main()
{
	vector<vector<int> > triangle;
	vector<int> row1;
	row1.push_back(1);
	
	vector<int> row2;
	row2.push_back(2);
	row2.push_back(3);
	
	triangle.push_back(row1);
	triangle.push_back(row2);
	
	
	cout << minimumTotalII(triangle) << endl;
}

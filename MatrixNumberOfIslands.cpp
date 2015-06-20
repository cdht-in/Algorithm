/*

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
	
*/
#include <vector>

using namespace std;

int numIslandsHelper(vector<vector<char> > &grid,int m, int n, int i, int j) 
{
	if(grid[i][j] == '1')
	{
		grid[i][j] = '0';
		
		//move to bottom
		if(i + 1 < m)
		{
			numIslandsHelper(grid,m,n,i + 1,j);
		}
		
		//move to right
		if(j + 1 < n)
		{
			numIslandsHelper(grid,m,n,i,j + 1);
		}
		
		
		//move to top
		if(i - 1 >= 0)
		{
			numIslandsHelper(grid,m,n,i - 1,j);
		}
		
		//move to left
		if(j - 1 >= 0)
		{
			numIslandsHelper(grid,m,n,i,j - 1);
		}
		
		//form an island
		return 1;	
	}
	
	return 0;
}

//O(n^2)
int numIslands(vector<vector<char> > &grid) 
{
	if(grid.size() == 0)
		return 0;
	int number = 0;
	int m = grid.size();
	int n = grid[0].size();

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			number += numIslandsHelper(grid,m,n,i,j);
		}
	}
	return number;
}

int main()
{
	
	
}
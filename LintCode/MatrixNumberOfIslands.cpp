/*
	
Given a boolean 2D matrix, find the number of islands.

Have you met this question in a real interview? Yes
Example
Given graph:

[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]
return 3.

Note
0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.
	
*/

#include "../commonHeader.h"

typedef pair<int,int> IntPair;

void MarkIsland(vector<vector<bool> >& grid,int i, int j)
{
	queue<IntPair> q;
	q.push(IntPair(i,j));
	while(q.empty() == false)
	{
		IntPair head = q.front();
		q.pop();
		grid[head.first][head.second] = false;
	
		if(head.first >= 1 && grid[head.first - 1][head.second])
		{
			q.push(IntPair(head.first - 1, head.second));
		}
	
		if(head.second >= 1 && grid[head.first][head.second - 1])
		{
			q.push(IntPair(head.first, head.second - 1));
		}
	
		if(head.first < grid.size() - 1 && grid[head.first + 1][head.second])
		{
			q.push(IntPair(head.first + 1, head.second));
		}
	
		if(head.second < grid[0].size() - 1 && grid[head.first][head.second + 1])
		{
			q.push(IntPair(head.first, head.second + 1));
		}
	}
}

int numIslands(vector<vector<bool> >& grid) 
{
	int c = 0;
	for(int i = 0; i < grid.size(); i++)
	{
		for(int j = 0; j < grid[0].size(); j++)
		{
			if(grid[i][j])
			{
				c++;
				MarkIsland(grid,i,j);
			}
		}
	}
	return c;
}

int main()
{
	
}
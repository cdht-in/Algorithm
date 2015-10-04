/*
	
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
	
*/

#include "./commonHeader.h"

//with extra memory, O(n^2) in time
void gameOfLife(vector<vector<int>>& board) 
{
	int m = board.size();
	if(m < 1)
		return;
	int n = board[0].size();
	vector<vector<int>> newBoard(m,vector<int>(n,0));
	int neightborX[] = {-1,-1,-1,0,1,1,1,0};
	int neightborY[] = {-1,0,1,1,1,0,-1,-1};
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int liveCount = 0;
			for(int k = 0; k < 8; k++)
			{
				int x = i + neightborX[k];
				int y = j + neightborY[k];
				if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 1)
				{
					liveCount++;
				}
			}
			
			if(board[i][j] == 1)
			{
				
				if(liveCount < 2 || liveCount > 3)
				{
					newBoard[i][j] = 0;
				}
				else
				{
					newBoard[i][j] = 1;
				}
			}
			else	
			{
				if(liveCount == 3)
				{
					newBoard[i][j] = 1;
				}
			}
		}
	}
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			board[i][j] = newBoard[i][j];
		}
	}
	
}

//in-place algorithm
void gameOfLifeI(vector<vector<int>>& board) 
{
	int m = board.size();
	if(m < 1)
		return;
	int n = board[0].size();
	
	
	/*
		there are four cases,
		1.current 1 -> 1, we leave it as it is 
		2.current 1 -> 0, we change 0 to 2, then later change 2 to 0
		3.current 0 -> 0, we leave it as it is 
		4.current 0 -> 1, we change 1 to -1, then later change -1 to 1
	
	*/
	int neightborX[] = {-1,-1,-1,0,1,1,1,0};
	int neightborY[] = {-1,0,1,1,1,0,-1,-1};
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int liveCount = 0;
			for(int k = 0; k < 8; k++)
			{
				int x = i + neightborX[k];
				int y = j + neightborY[k];
				if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] > 0)
				{
					liveCount++;
				}
			}
			
			if(board[i][j] == 1)
			{
				if(liveCount < 2 || liveCount > 3)
				{
					board[i][j] = 2;
				}
			}
			else	
			{
				if(liveCount == 3)
				{
					board[i][j] = -1;
				}
			}
		}
	}
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(board[i][j] == 2)
			{
				board[i][j] = 0;
			}
			else if(board[i][j] == -1)
			{
				board[i][j] = 1;
			}
		}
	}
	
}


int main()
{
	
}
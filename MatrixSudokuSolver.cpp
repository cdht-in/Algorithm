/*

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.
	
*/

#include <vector>
#include <iostream>

using namespace std;

bool isValidSudoku(vector<vector<char> > &board, int i, int j) {
	
	int n = 9;
	int row[n + 1];
	int col[n + 1];
	
	//check row
	memset(row,0,(n + 1) * sizeof(int));
	for(int k = 0; k < n; k++)
	{
		if(board[k][j] == '.')
			continue;
		
		if(row[board[k][j] - '0'] == 0)
			row[board[k][j] - '0'] = 1;
		else
			return false;
	}	
		
	//check column
	memset(col,0,(n + 1) * sizeof(int));
	for(int k = 0; k < n; k++)
	{
		
		if(board[i][k] == '.')
			continue;
		
		if(col[board[i][k] - '0'] == 0)
			col[board[i][k] - '0'] = 1;
		else
			return false;
	}
	
	//check each grid
	int grid[n + 1];
	int startI = (i / 3) * 3;
	int startJ = (j / 3) * 3;
	
	memset(grid,0,(n + 1) * sizeof(int));
	
	for(int k1 = 0; k1 < 3; k1++)
	{
		for(int k2 = 0; k2 < 3; k2++)
		{
			if(board[startI + k1][startJ + k2] == '.')
				continue;
			
			if(grid[board[startI + k1][startJ + k2] - '0'] == 0)
				grid[board[startI + k1][startJ + k2] - '0'] = 1;
			else
				return false;
		}
	}
	
	return true;
}


//brute force
bool solveSudokuHelper(vector<vector<char> > &board,int n,int row, int col) {
	if(col >= n)
	{
		return solveSudokuHelper(board,n,row + 1,0);
	}
	if(row == n)
		return true;
	
	if(board[row][col] == '.')
	{
		for(int k = 1; k <= n; k++)
		{
			board[row][col] = (char)('0' + k);
			if(isValidSudoku(board,row,col))
			{
				if(solveSudokuHelper(board, n, row, col + 1))
					return true;
			}
			board[row][col] = '.';
		}
	}
	else
	{
		return solveSudokuHelper(board,n, row, col + 1);
	}
	return false;
	
}

void solveSudoku(vector<vector<char> > &board) {
	if(board.size() == 0)
		return;
	int n = 9;
	solveSudokuHelper(board,n,0,0);			
}

//BFS approach will be added later
//http://yucoding.blogspot.com/2013/12/leetcode-question-sudoku-solver.html

int main()
{
	
	
}
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void Mark(vector<string> & board, int row,int col, int n,char c)
{
	//mark the col
	for(int i = row - 1; i >= 0; i--)
	{
		board[i][col] = c;
	}
	
	for(int i = row + 1; i < n; i++)
	{
		board[i][col] = c;
	}
	
	//mark this row
	
	for(int i = col + 1; i < n; i++)
	{
		board[row][i] = c;
	}
	
	//mark the diagnol
	
	int i = row;
	int j = col;
	
	while(i >= 1 && j < n - 1)
	{
		board[i - 1][j + 1] = c;
		i--;
		j++;
	}
	
	i = row;
	j = col;
	while(i < n - 1 && j < n - 1)
	{
		board[i + 1][j + 1] = c;
		i++;
		j++;
	}
}

bool solveNQueensHelper(vector<string> & board, int col, int n, int& c)
{	
	if(col >= n)
	{
		c++;
		return true;
	}
	
	for(int row = 0; row < n; row++)
	{
		if(board[row][col] != '.')
		{
			//save the board state
			vector<string>  preMark(board);
			
			Mark(board,row,col,n,'.');
			board[row][col] = 'Q';
						
			if(solveNQueensHelper(board,col + 1,n,c) == false)
			{
				//restore the board
				board.assign(preMark.begin(),preMark.end());					
			}
		}
	}
	
	return false;
}

int solveNQueens(int n) {
	int c = 0;
	if(n == 0)
		return c;
		
	vector<string> board(n,string(n,'0'));
	solveNQueensHelper(board,0,n,c);
	
	return c;
}

int main(){
	
	
}

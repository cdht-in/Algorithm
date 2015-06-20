/*

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
	
*/

#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char> > &board) {
	if(board.size() == 0)
		return false;
	//should be 9
	int n = board.size();
	
	int row[n + 1];
	int col[n + 1];
	
	//check row
	for(int i = 0; i < n; i++)
	{
		memset(row,0,(n + 1) * sizeof(int));
		for(int j = 0; j < n; j++)
		{
			if(board[i][j] == '.')
				continue;
			
			if(row[board[i][j] - '0'] == 0)
				row[board[i][j] - '0'] = 1;
			else
				return false;
		}		
	}
	
	//check column
	for(int i = 0; i < n; i++)
	{
		memset(col,0,(n + 1) * sizeof(int));
		for(int j = 0; j < n; j++)
		{
			if(board[j][i] == '.')
				continue;
			
			if(col[board[j][i] - '0'] == 0)
				col[board[j][i] - '0'] = 1;
			else
				return false;
		}
	}
	
	//check each grid
	int grid[n + 1];
	for(int i = 0; i < n; i += 3)
	{
		for(int j = 0; j < n; j += 3)
		{
			memset(grid,0,(n + 1) * sizeof(int));
			
			for(int k1 = 0; k1 < 3; k1++)
			{
				for(int k2 = 0; k2 < 3; k2++)
				{
					if(board[i + k1][j + k2] == '.')
						continue;
			
					if(grid[board[i + k1][j + k2] - '0'] == 0)
						grid[board[i + k1][j + k2] - '0'] = 1;
					else
						return false;
				}
			}	
		}
	}
	
	return true;
}

int main()
{
	
	
}
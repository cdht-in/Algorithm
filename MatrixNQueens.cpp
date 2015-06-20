/*
	
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
	
*/

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

bool solveNQueensHelper(vector<string> & board, int col, int n,vector<vector<string> >& result)
{	
	if(col >= n)
	{
		result.push_back(board);
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
			
			//board
			
			/*
			for(int i = 0; i <  board.size(); i++)
			{
				cout << board[i] << endl;
			}
			cout << "----------" << endl;
			*/
			
			if(solveNQueensHelper(board,col + 1,n,result) == false)
			{
				//restore the board
				
				board.assign(preMark.begin(),preMark.end());
				
				/*
				cout << "restoring board " << endl;
				for(int i = 0; i <  board.size(); i++)
				{
					cout << board[i] << endl;
				}
				cout << "----------" << endl;
				*/
				
			}
		}
	}
	
	return false;
}

vector<vector<string> > solveNQueens(int n) {
	vector<vector<string> > result;
	if(n == 0)
		return result;
		
	vector<string> board(n,string(n,'0'));
	solveNQueensHelper(board,0,n,result);
	
	return result;
}



































vector<vector<string> > res;

void printres(vector<int> A,int n)
{
	vector<string> r;
	for(int i = 0;i < n;i++)
	{
	    string str(n,'.');
	    str[A[i]] = 'Q';
	    r.push_back(str);
	}
	res.push_back(r);
}

bool isValid(vector<int> A, int row)
{
	for(int i = 0; i < row; i++)
	{
		//if there is a queen in the same col or
	    if ((A[i] == A[row]) || (abs(A[i] - A[row]) == (row - i)))
		{
	        return false;
	    }
	}
	return true;
}      	

void nqueens(vector<int> A, int row, int n)
{
	if (row == n)
	{
		printres(A,n);
	}
	else
	{
	    for (int col = 0; col < n ;col++)
		{
			//place a queen at [row, col]
	        A[row] = col;
			
	        if (isValid(A,row))
			{
	            nqueens(A,row + 1,n);
	        }
	    }
	}
}


//second implementation
vector<vector<string> > solveNQueensI(int n) 
{
    res.clear();
    vector<int> A(n,-1);
    nqueens(A,0,n);
    return res;
}

bool IsValid(vector<int>& queenPos, int col)
{
	for(int i = 0; i < col; i++)
	{
		//if there is a queen in the column
		if(queenPos[i] == queenPos[col])
		{
			return false;
		}
		
		if(std::abs(queenPos[i] - queenPos[col]) == col - i)
		{
			return false;
		}
		
	}
	return true;
}

void solveNQueensIIHelper(int start, int end,vector<int>& queenPos,vector<vector<string> >& result)
{
	if(start > end)
	{
		//fill result with the board
		vector<string> board(end,string(end,'.'));
		
		for(int i = 0; i < end; i++)
		{
			board[queenPos[i]][i] = 'Q';
		}	
		
		result.push_back(board);
		
		return;
	}
	
	//loop through each row
	for(int i = 0; i <= end; i++)
	{
		queenPos[start] = i;
		
		//check if the queen's position is valid
		if(IsValid(queenPos,start))
		{
			solveNQueensIIHelper(start + 1, end,queenPos,result);
		}
		
	}
}

//third implementation
vector<vector<string> > solveNQueensII(int n) 
{    
	vector<vector<string> > result;
	if(n == 0)
		return result;
	
	vector<int> queenPos(n, -1);
	
	solveNQueensIIHelper(0,n - 1, queenPos,result);
			
	return result;
}

int main()
{
	vector<vector<string> > result = solveNQueens(4);
	
	cout << result.size() << endl;
	
	/*	
	for(int i = 0; i < result.size(); i++)
	{
		for(int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << endl;
		}		
		cout << endl;
	}
	*/
		
}
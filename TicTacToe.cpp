#include "./commonHeader.h"

class TicTacToe
{
	bool mTurn;
	int mDimension;
	int mFilled;
	vector<vector<char> > board;
	enum mOutCome{win,tie,unfinished};
	
	mOutCome Win(int x,int y)
	{
		//check column
		bool win = true;
		for(int i = 0; i < mDimension - 1; i++)
		{
			if(board[x][i] == 'X' && board[x][i] != board[x][i + 1])
				win = false;
			if(board[x][i] == 'O' && board[x][i] != board[x][i + 1])
				win = false;
			if(board[x][i] == ' ')
				win = false;
		}
		
		if(win)
			return mOutCome::win;
		
		win = true;
		
		//check row
		for(int i = 0; i < mDimension - 1; i++)
		{
			if(board[i][y] == 'X' && board[i][y] != board[i + 1][y])
				win = false;
			if(board[i][y] == 'O' && board[i][y] != board[i + 1][y])
				win = false;
			if(board[i][y] == ' ')
				win = false;
		}
		
		if(win)
			return mOutCome::win;
		
		win = true;
		
		//left diagonal
		for(int i = 0; i < mDimension - 1; i++)
		{
			if(board[i][i] == 'X' && board[i][i] != board[i + 1][i + 1])
				win = false;
			if(board[i][i] == 'O' && board[i][i] != board[i + 1][i + 1])
				win = false;
			if(board[i][i] == ' ')
				win = false;
		}
		
		if(win)
			return mOutCome::win;
		
		win = true;
		
		//right diagonal
		for(int i = 0; i < mDimension - 1; i++)
		{
			if(board[mDimension - 1 - i][i] == 'X' && board[mDimension - 1 - i][i] != board[mDimension - 1 - i - 1][i + 1])
				win = false;
			if(board[mDimension - 1 - i][i] == 'O' && board[mDimension - 1 - i][i] != board[mDimension - 1 - i - 1][i + 1])
				win = false;
			if(board[mDimension - 1 - i][i] == ' ')
				win = false;
		}
		
		if(win)
			return mOutCome::win;
		
		if(mFilled >= mDimension * mDimension)
			return mOutCome::tie;
		
		return mOutCome::unfinished;
	}
	
public:
	TicTacToe():mTurn(true),mDimension(3),board(vector<vector<char> >(mDimension,vector<char>(mDimension,' '))),mFilled()
	{
	}
	
	bool Place(int x,int y)
	{
		if(x < 0 || y < 0 || x >= mDimension || y >= mDimension)
			throw "Out of bound";
		
		bool win = false;
		if(board[x][y] != ' ')
		{
			cout << "Can't place on the existing tile" << endl;
			return win;
		}
		
		mFilled++;
		if(mTurn)
		{
			board[x][y] = 'X';
		}
		else
		{
			board[x][y] = 'O';
		}
		mOutCome result = Win(x,y);
		if(result == mOutCome::win)
		{
			if(mTurn)
			{
				cout << "First player win" << endl;
				win = true;
			}
			else
			{
				cout << "Second player win" << endl;
				win = true;	
			}
		}
		else if(result == mOutCome::tie)
		{
			cout << "It's a tie" << endl;
			win = true;
		}
				
		PrintBoard();
		mTurn = !mTurn;
		return win;
	}
	
	void Reset(bool reset = false)
	{
		if(reset == false)
			return;
		board = vector<vector<char> >(mDimension,vector<char>(mDimension,' '));
	}
	
	void PrintBoard()
	{
		for(int i = 0; i < mDimension; i++)
		{
			for(int j = 0; j < mDimension; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	TicTacToe ticTacToe;
	int x = 0, y = 0;
	string input = "";
	int myNumber;
    while (true) 
	{
		getline(cin, input);
		
		if(input.size() < 3)
		{
			cout << "Please re-place the tile" << endl;
			continue;
		}
		
		string xString = input.substr(0,1);
		string yString = input.substr(2,1);
		
      	// This code converts from string to number safely.
      	stringstream myStreamX(xString);
		myStreamX >> x;
		
      	stringstream myStreamY(yString);
		myStreamY >> y;
		
		if(ticTacToe.Place(x,y))
			break;
    }
}
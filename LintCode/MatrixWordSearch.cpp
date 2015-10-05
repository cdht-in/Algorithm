/*

Medium Word Search

25% Accepted
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Have you met this question in a real interview? Yes
Example
Given board =

[
  "ABCE",
  "SFCS",
  "ADEE"
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
	
*/

#include "../commonHeader.h"

bool exist(vector<vector<char> > &board,int i, int j, int index, string& word, vector<vector<bool> >& visited)
{
	//NOTE that this condition should go first
	if(index >= word.size())
	{
		return true;
	}
	
	if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index])
	{
		return false;
	}
	
	int directionX[] = {-1,0,1,0};
	int directionY[] = {0,1,0,-1};
	
	visited[i][j] = true;
	
	for(int k = 0; k < 4; k++)
	{
		int x = i + directionX[k];
		int y = j + directionY[k];
		
		if(exist(board,x,y,index + 1, word,visited))
			return true;
	}
	
	visited[i][j] = false;
	
	return false;
}

bool exist(vector<vector<char> > &board, string word) 
{
	int m = board.size();
	if(m == 0)
		return false;
	int n = board[0].size();
	vector<vector<bool> > visited(m,vector<bool>(n,false));
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(exist(board,i,j,0,word,visited))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	
}
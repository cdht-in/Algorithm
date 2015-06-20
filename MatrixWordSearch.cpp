/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
	
*/

#include <vector>
#include <iostream>

using namespace std;

using namespace std;

//op is the direction for not go back where it came from
//0 == top, 1 == right, 2 == bottom, 3 == left
bool existHelper (vector<vector<char> >& board, vector<vector<int> >& visit, const string& word, int matchlen, int op, int x, int y)
{
  if (matchlen == word.size() )
    return true;
  //top
  if ( (x - 1 >= 0) && (board[x - 1][y] == word[matchlen]) && (visit[x - 1][y] == 0) && (op != 0) ) {
    visit[x - 1][y] = 1;
    if (existHelper (board, visit, word, matchlen + 1, 2, x - 1, y) )
      return true;
    visit[x - 1][y] = 0;
  }
  //right
  if ( (y + 1 < board[0].size() ) && (board[x][y + 1] == word[matchlen]) && (visit[x][y + 1] == 0 && (op != 1) ) ) {
    visit[x][y + 1] = 1;
    if (existHelper (board, visit, word, matchlen + 1, 3, x, y + 1) )
      return true;
    visit[x][y + 1] = 0;
  }
  //down
  if ( (x + 1 < board.size()) && (board[x + 1][y] == word[matchlen]) && (visit[x + 1][y] == 0) && (op != 2) ) {
    visit[x + 1][y] = 1;
    if (existHelper (board, visit, word, matchlen + 1, 0, x + 1, y) )
      return true;
    visit[x + 1][y] = 0;
  }
  //left
  if ( (y - 1 >= 0) && (board[x][y - 1] == word[matchlen]) && (visit[x][y - 1] == 0 && (op != 3) ) ) {
    visit[x][y - 1] = 1;
    if (existHelper (board, visit, word, matchlen + 1, 1, x, y - 1) )
      return true;
    visit[x][y - 1] = 0;
  }
  return false;
}

bool exist (vector<vector<char> >& board, string word)
{
  if (word.size() < 1 || board.size() < 1 || board[0].size() < 1)
    return false;
  int row = board.size();
  int col = board[0].size();
  vector<vector<int> > visit (row, vector<int> (col, 0) );
  for (int i = 0; i < row; i++) 
  {
    for (int j = 0; j < col; j++) 
	{
      int matchlen = 0;
      if (board[i][j] == word[matchlen]) 
	  {
        visit[i][j] = 1;
        if (existHelper (board, visit, word, matchlen + 1, -1, i, j) )
          return true;
        visit[i][j] = 0;
      }
    }
  }
  return false;
}


//second implementation
bool existIHelper(vector<vector<char> > &board,int i, int j,int m, int n, string& word,int index,vector<bool>& visited)
{
	
    if(index == word.size())
	{
		return true;
	}
		
	int pos = i * n + j;
	
	if(i > m - 1 || j > n - 1 || i < 0 || j < 0 || visited[pos] == true || board[i][j] != word[index])
		return false;
	
	
	visited[pos] = true;
	if(existIHelper(board,i - 1, j,m,n,word,index + 1, visited))
		return true;
	if(existIHelper(board,i + 1, j,m,n,word,index + 1, visited))
		return true;
	if(existIHelper(board,i, j - 1,m,n,word,index + 1, visited))
		return true;
	if(existIHelper(board,i, j + 1,m,n,word,index + 1, visited))
		return true;
	
	visited[pos] = false;
	
	return false;
}

bool existI(vector<vector<char> > &board, string word) {
	if(board.size() == 0)
		return false;
	int m = board.size();
	int n = board[0].size();
	int mn = m * n;
	
	if(mn < word.size())
		return false;
	
	vector<bool> visited(mn,false);
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			visited.clear();
			visited.resize(mn,false);
			if(existIHelper(board,i,j,m,n,word,0,visited))
				return true;
		}
	}
	return false;
}


//third implementation
bool existIIHelper(vector<vector<char> >& board, vector<vector<bool> >& visited,int i, int j, string word, int start)
{
	if(start >= word.size())
		return true;
	
	if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] == true || word[start] != board[i][j])
		return false;
	
	visited[i][j] = true;
	
	if(	existIIHelper(board,visited,i - 1, j, word, start + 1) || 
		existIIHelper(board,visited,i + 1, j, word, start + 1) ||
		existIIHelper(board,visited,i, j - 1, word, start + 1) || 
		existIIHelper(board,visited,i, j + 1, word, start + 1))
			return true;
	
	visited[i][j] = false;
	
	return false;
}

bool existII (vector<vector<char> >& board, string word)
{
	if(board.size() < 1)
		return false;
	
	int m = board.size();
	int n = board[0].size();
	
	vector<vector<bool> > visited(m,vector<bool>(n,false));
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(existIIHelper(board,visited,i,j,word,0))
				return true;
		}
	}
	
	return false;
}


int main(){
	
    vector<vector<char> > board;
    board.push_back (vector<char> ( {'A', 'B', 'C', 'E'}) );
    board.push_back (vector<char> ( {'S', 'F', 'C', 'S'}) );
    board.push_back (vector<char> ( {'A', 'D', 'E', 'E'}) );
    string word = "ABCE";
    cout << existII (board, word) << endl;
}
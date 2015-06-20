/*
  Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'. A region is captured by flipping all 'O's into 'X's in that surrounded region .

  For example,

  X X X X
  X O O X
  X X O X
  X O X X
  After running your function, the board should be:

  X X X X
  X X X X
  X X X X
  X O X X

*/

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

//BFS search
void MarkA (char** mat, int x, int y, int size)
{
  if (mat[x][y] == 'O') {
    mat[x][y] = 'A';
    //into 'X's in that surrounded region.
    //For example,//check its neighbors, i.e 4 neighors
    if (x - 1 >= 0)
      MarkA (mat, x - 1, y, size);
    if (y - 1 >= 0)
      MarkA (mat, x, y - 1, size);
    if (x + 1 < size)
      MarkA (mat, x + 1, y, size);
    if (y + 1 < size)
      MarkA (mat, x, y + 1, size);
  }
}

//O(n^2)
void Reverse (char** mat, int size)
{
  //first flip  'O's into 'X's in that surrounded region.
  //For example,all boundary 'O' to 'A'
  for (int i = 0; i < size; i++) {
    if (i == 0 || i == size - 1) {
      for (int j = 0; j < size; j++) {
        if (mat[i][j] == 'O')
          MarkA (mat, i, j, size);
      }
    }
    else {
      for (int j = 0; j < size; j += size - 1)
        if (mat[i][j] == 'O')
          MarkA (mat, i, j, size);
    }
  }
  //then the rest is all insolated 'O'
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (mat[i][j] == 'O')
        mat[i][j] = 'X';
    }
  }
  //last all 'A' back to 'O'
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (mat[i][j] == 'A')
        mat[i][j] = 'O';
    }
  }
}

void PrintMat (char** mat, int size)
{
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf ("%c ", mat[i][j]);
    }
    printf ("\n");
  }
}


void Mark (vector<vector<char> >& board, int x, int y, int row, int col)
{
  while(board[x][y] == '0'){
    
  }
  if (board[x][y] == 'O') {
    board[x][y] = 'A';
    if (x - 1 >= 0)
      Mark (board, x - 1, y, row, col);
    if (y - 1 >= 0)
      Mark (board, x, y - 1, row, col);
    if (x + 1 < row)
      Mark (board, x + 1, y, row, col);
    if (y + 1 < col)
      Mark (board, x, y + 1, row, col);
  }
}

void solve (vector<vector<char> >& board)
{
  if (board.size() > 0 && board[0].size() > 0) {
    int row = board.size();
    int col = board[0].size();
    for (int i = 0; i < row; i++) {
      if (i == 0 || i == row - 1) {
        for (int j = 0; j < col; j++) {
          if (board[i][j] == 'O')
            Mark (board, i, j, row, col);
        }
      }
      else {
        for (int j = 0; j < col; j += col - 1)
          if (board[i][j] == 'O')
            Mark (board, i, j, row, col);
          }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (board[i][j] == 'A')
          board[i][j] = 'O';
      }
    }
  }
}



int main()
{
  
}







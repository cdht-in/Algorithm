/*

  Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

  The Sudoku board could be partially filled, where empty cells are filled with the character '.'

*/

#include <vector>

using namespace std;

bool isValidSudoku (vector<vector<char> >& board)
{
  int nrow = 9;
  int ncol = 9;
  int nblock = 9;
  int* row[nrow];
  int* col[ncol];
  int* block[nblock];
  for (int i = 0; i < nrow; i++) {
    row[i] = new int[ncol];
    for (int j = 0; j < ncol; j++)
      row[i][j] = 0;
  }
  for (int i = 0; i < ncol; i++) {
    col[i] = new int[nrow];
    for (int j = 0; j < nrow; j++)
      col[i][j] = 0;
  }
  for (int i = 0; i < nblock; i++) {
    block[i] = new int[nblock];
    for (int j = 0; j < nblock; j++)
      block[i][j] = 0;
  }
  for (int i = 0; i < nblock; i++) {
    for (int j = i - (i % 3); j < i - (i % 3) + 3; j++) {
      for (int k = (i % 3) * 3; k < (i % 3) * 3 + 3; k++) {
        if (board[j][k] != '.') {
          //already exist in the block
          if (block[i][board[j][k] - 1] == 1)
            return false;
          else
            block[i][board[j][k] - 1] = 1;
          //already exist in the row
          if (row[j][board[j][k] - 1] == 1)
            return false;
          else
            row[j][board[j][k] - 1] = 1;
          if (col[k][board[j][k] - 1] == 1)
            return false;
          else
            col[k][board[j][k] - 1] = 1;
        }
      }
    }
  }
  for (int i = 0; i < nrow; i++)
    delete[] row[i];
  for (int i = 0; i < ncol; i++)
    delete[] col[i];
  for (int i = 0; i < nblock; i++)
    delete[] block[i];
  return true;
}


int main()
{
}

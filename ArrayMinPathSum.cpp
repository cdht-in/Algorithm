/*
  Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

  Note: You can only move either down or right at any point in time.
*/
#include <vector>

using namespace std;

int minPathSum (vector<vector<int> >& grid)
{
  if (grid.size() < 1 || grid[0].size() < 1)
    return 0;
  int row = grid.size();
  int col = grid[0].size();
  int* sum[row];
  for (int i = 0; i < row; i++) {
    sum[i] = new int[col];
  }
  sum[0][0] = grid[0][0];
  for (int i = 1; i < col; i++) {
    sum[0][i] = sum[0][i - 1] + grid[0][i];
  }
  for (int i = 1; i < row; i++) {
    sum[i][0] = sum[i - 1][0] + grid[i][0];
  }
  for (int i = 1; i < row; i++) {
    for (int j = 1; j < col; j++) {
      sum[i][j] = ( (sum[i - 1][j] < sum[i][j - 1]) ? sum[i - 1][j] : sum[i][j - 1]) + grid[i][j];
    }
  }
  int ret = sum[row - 1][col - 1];
  for (int i = 0; i < row; i++) {
    delete[] sum[i];
  }
  return ret;
}


int main()
{
}

/*
  Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

  For example,
  Given the following matrix:

  [
  [ 1, 2, 3 ],
  [ 4, 5, 6 ],
  [ 7, 8, 9 ]
  ]
  You should return [1,2,3,6,9,8,7,4,5].

*/

#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

//start from the top left corner and reduce the range at each iteration, and which direction I am walking torward
void SpiralPrint (int** data, int x, int y, int min, int max)
{
  //odd dimension
  if (max - min == 1) {
    printf ("%d\n", data[x][y]);
    return;
  }
  //even dimension
  if (max == min) {
    printf ("\n");
    return;
  }
  //left to right
  for (; y < max; y++)
    printf ("%d ", data[x][y]);
  x++;
  y--;
  //top to down
  for (; x < max; x++)
    printf ("%d ", data[x][y]);
  x--;
  y--;
  //right to left
  for (; y >= min; y--)
    printf ("%d ", data[x][y]);
  y++;
  x--;
  //bottom to top
  for (; x > min; x--)
    printf ("%d ", data[x][y]);
  SpiralPrint (data, x + 1, y + 1, min + 1, max - 1);
}



vector<int> spiralOrder (vector<vector<int> >& data)
{
  vector<int> ret;
  if (data.size() < 1 || data[0].size() < 1)
    return ret;
  int row = data.size();
  int col = data[0].size();
  if (row == 1) {
    for (int i = 0; i < col; i++)
      ret.push_back (data[0][i]);
    return ret;
  }
  else if (col == 1) {
    for (int i = 0; i < row; i++)
      ret.push_back (data[i][0]);
    return ret;
  }
  int x = 0 , y = 0;
  int centerx = row / 2;
  int centery = col / 2;
  while (x < centerx && y < centery) {
    //left to right
    for (int i = y; i < col - 1 - y; i++) {
      ret.push_back (data[x][i]);
    }
    //top to down
    for (int i = x; i < row - 1 - x; i++) {
      ret.push_back (data[i][col - 1 - y]);
    }
    //right to left
    for (int i = col - 1 - y; i > y; i--) {
      ret.push_back (data[row - 1 - x][i]);
    }
    //bottom to top
    for (int i = row - 1 - x; i > x; i--) {
      ret.push_back (data[i][y]);
    }
    x++;
    y++;
  }
  return ret;
}

int main()
{
  vector<vector<int> >matrix = {{1, 2, 3},{4, 5, 6}, {7, 8, 9}};
for (auto i : spiralOrder (matrix) )
    cout << i << " ";
  cout << endl;
}

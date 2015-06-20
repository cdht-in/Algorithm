/*
  Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

  For example,
  Given n = 3,

  You should return the following matrix:
  [
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
  ]
*/
#include <cstdio>
#include <vector>

using namespace std;

void SpiralMatrix (int n, int** matrix)
{
  int x = 0, y = 0;
  int len = n * n;
  for (int i = 0; i < len; i++) {
    matrix[x][y] = i + 1;
    if (x >= n - 1 - y && x < y) {
      x++;
      printf ("%d\n", matrix[x - 1][y]);
    }
    else if (y > n - 1 - x && y <= x) {
      y--;
      //printf("2 %d %d\n",x,y);
    }
    else if (x > y + 1 && x <= n - 1 - y) {
      x--;
      //printf("3 %d %d\n",x,y);
    }
    else {
      y++;
      //printf("4 %d %d\n",x,y);
    }
  }
}

//O(n)
void SpiralMatrixII (int n, int** mat)
{
  int centerx = 0;
  int centery = 0;
  int m = 1;
  while (centerx <= n / 2 && centery <= n / 2) {
    //top
    int row = centerx;
    int col = centery;
    for (; col < n - centery; col++) {
      mat[row][col] = m++;
    }
    //right
    for (row++, col--; row < n - centery; row++) {
      mat[row][col] = m++;
    }
    //bottom
    for (row--, col--; col >= centery; col--) {
      mat[row][col] = m++;
    }
    //left
    for (col++, row--; row > centerx; row--) {
      mat[row][col] = m++;
    }
    //move the starting point along the diagonal from the top left corner
    centerx++;
    centery++;
  }
}

vector<vector<int> > generateMatrix (int n)
{
  int centerx = 0;
  int centery = 0;
  int m = 1;
  vector<vector<int > > mat;
  if(n < 1)
    return mat;
  for(int i = 0; i < n; i++){
    mat.push_back(vector<int>(n,0));
  }
  while (centerx <= n / 2 && centery <= n / 2) {
    //top
    int row = centerx;
    int col = centery;
    for (; col < n - centery; col++) {
      mat[row][col] = m++;
    }
    //right
    for (row++, col--; row < n - centery; row++) {
      mat[row][col] = m++;
    }
    //bottom
    for (row--, col--; col >= centery; col--) {
      mat[row][col] = m++;
    }
    //left
    for (col++, row--; row > centerx; row--) {
      mat[row][col] = m++;
    }
    //move the starting point along the diagonal from the top left corner
    centerx++;
    centery++;
  }
}




int main()
{
  vector<vector<int> > mat = generateMatrix(0);
}



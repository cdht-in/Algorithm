/*
  Search for x in a sorted matrix
*/

#include <cstdio>
#include <vector>

using namespace std;

int** matrix;

//Note that alone the diagonal, if the target is bigger than x, it could be anywhere in the 2,3,4 but not 1, conversely, if the target is smaller than x, it could be in 1,2,3 but not 4, this expontially decrease the search area. use the topleft and bottomright coordicates to restrict the search area
bool Locate (int target, int** matrix, int tx, int ty, int bx, int by)
{
  //this is an empty matrix
  if (tx > bx && ty > by) {
    printf ("not found \n");
    return false;
  }
  int midx = (tx + bx) / 2;
  int midy = (ty + by) / 2;
  if (target == matrix[midx][midy]) {
    printf ("found target(%d) at (%d,%d)\n", target, midx, midy);
    return true;
  }
  //start with the topleft corner than walk down the diagonal
  if (target < matrix[midx][midy]) {
    //search in areas except 4
    Locate (target, matrix, tx + 1, ty + 1, midx - 1, midy - 1);
  }
  else {
    bool found = Locate (target, matrix, midx + 1, midy + 1, bx, by);
    if (!found)
      found = Locate (target, matrix, tx, midy + 1, midx, by);
    if (!found)
      Locate (target, matrix, midx + 1, ty, bx, midy);
    return found;
  }
}

//stepwise binary search,start at the top right corner
bool LocateStepwise (int target, int** matrix, int row, int col, int x, int y)
{
  if (x < 0 || x >= row || y < 0 || y >= col)
    return false;
  printf ("in %d %d\n", x, y);
  if (matrix[x][y]  == target)
    return true;
  if (target < matrix[x][y])
    return LocateStepwise (target, matrix, row, col, x, y - 1);
  else
    return LocateStepwise (target, matrix, row, col, x + 1, y);
}


/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

  Consider the following matrix:

  [
   [1,   3,  5,  7],
   [10, 11, 16, 20],
   [23, 30, 34, 50]
   ]
  Given target = 3, return true.
*/

bool searchMatrix (vector<vector<int> >& matrix, int target)
{
  if (matrix.size() < 1 || matrix[0].size() < 1)
    return false;
  int x = 0;
  int y = matrix[0].size() - 1;
  while (x < matrix.size() && x >= 0 && y < matrix[0].size() && y >= 0) {
    if(matrix[x][y] == target)
      return true;
    else if(matrix[x][y] < target)
      x++;
    else
      y--;
  }
  return false;
}


int main()
{
  int dim = 5;
  matrix = new int*[dim];
  for (int i = 0; i < dim; i++)
    matrix[i] = new int[dim];
  /*
    matrix[0][0] = 0;
    matrix[0][1] = 1;
    matrix[1][0] = 2;
    matrix[1][1] = 3;
  */
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++)
      matrix[i][j] = i + j;
  }
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      printf ("%d ", matrix[i][j]);
    }
    printf ("\n");
  }
  //to begin searching the entire matrix
  printf ("%d\n", LocateStepwise (5, matrix, dim, dim, 0, dim - 1) );
}

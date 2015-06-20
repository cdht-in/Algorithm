/*
  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
  click to show follow up.
  Follow up:
  Did you use extra space?
  A straight forward solution using O(mn) space is probably a bad idea.
  A simple improvement uses O(m + n) space, but still not the best solution.
  Could you devise a constant space solution?
*/

#include <cstdio>
#include <vector>

using namespace std;

void PrintMat (int** mat, int m, int n)
{
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf ("%d ", mat[i][j]);
    }
    printf ("\n");
  }
  printf ("\n");
}

//O(1) space
void SetMatZero (int** mat, int m, int n)
{
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      //
      if (mat[i][j] == 0) {
        for (int col = 0; col < n; col++)
          mat[i][col] = 99;
        for (int row = 0; row < m; row++) {
          mat[row][j] = 99;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == 99)
        mat[i][j] = 0;
    }
  }
}

//only works if there is no 9999 in the original matrix
void setZeroes(vector<vector<int> > &matrix) {
  if(matrix.size() < 1 || matrix[0].size() < 1)
    return;
  int row = matrix.size();
  int col = matrix[0].size();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if(matrix[i][j] == 0){
	for (int k = 0; k < row; k++) {
	  if(matrix[k][j] != 0)
	    matrix[k][j] = 9999;
	}
	for (int k = 0; k < col; k++) {
	  if(matrix[i][k] != 0)
	    matrix[i][k] = 9999;
	}
      }
    }
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if(matrix[i][j] == 9999)
	matrix[i][j] = 0;
    }
  }
}

int main()
{
  int m = 3;
  int n = 4;
  int** mat = new int*[m];
  for (int i = 0; i < m; i++) {
    mat[i] = new int[n];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = i + j;
    }
  }
  PrintMat (mat, m, n);
  SetMatZero (mat, m, n);
  PrintMat (mat, m, n);
}

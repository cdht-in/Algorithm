/*
  You are given an n x n 2D matrix representing an image.
  Rotate the image by 90 degrees (clockwise).
  Follow up:
  Could you do this in-place?
*/

#include <vector>
#include <iostream>

using namespace std;

void PrintMatrix (vector<vector<int> >& mat)
{
for (auto i: mat) {
  for (auto j: i) {
      cout << j << " ";
    }
    cout << endl;
  }
}

void rotate (vector<vector<int> >& matrix)
{
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  int n = matrix.size();
  for (int layer = 0; layer < n / 2; layer++) {
    int first = layer;
    int last  = n - 1 - layer;
    for (int i = first; i < last; i++) {
      int offset = i - first;
      int top = matrix[first][i];
      //left->top
      matrix[first][i] = matrix[last - offset][first];
      //bottom->top
      matrix[last - offset][first] = matrix[last][last - offset];
      //right->bottom
      matrix[last][last - offset] = matrix[i][last];
      //top->right
      matrix[i][last] = top;
      PrintMatrix(matrix);
    }
  }
}

int main()
{
  vector<vector<int> > matrix = {{0, 1}, {2, 3}};
  rotate(matrix);
}

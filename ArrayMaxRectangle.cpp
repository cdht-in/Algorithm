/*
  Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/
#include <vector>
#include <iostream>

using namespace std;

int maximalRectangle (vector<vector<char> >& matrix)
{
  if (matrix.size() < 1 || matrix[0].size() < 1)
    return 0;
  int row = matrix.size();
  int col = matrix[0].size();
  int max = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (matrix[i][j] == '1') {
        int r = col;
        int b = 0;
        //find the leftmost 0
        for (int q = j; q < col; q++) {
          int f = false;
          int p = i;
          for (; p < row; p++) {
            if (matrix[p][q] == '0') {
              r = q;
              f = true;
              break;
            }
          }
          b = (b > p) ? b : p;
          if (f) {
            break;
          }
        }
        int area = (b - i) * (r - j);
        max = (max > area) ? max : area;
      }
    }
  }
  return max;
}



//check if the submatrix is all ones
bool AllOnesMatrix (vector<vector<char> >& matrix, int tr, int tc, int br, int bc)
{
  for (int i = tr; i <= br; i++) {
    for (int j = tc; j <= bc; j++) {
      if (matrix[i][j] == '0')
        return false;
    }
  }
  return true;
}

//brute force O(m^3 * n^3), m^2 * n^2 to find all rectangles and m * n to examine it having all ones
int maximalRectangleBruteForce (vector<vector<char> >& matrix)
{
  int maxsize = 0;
  int area = 0;
  //find all top left corner
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      //find all bottom right corner
      for (int m = i; m < matrix.size(); m++) {
        for (int n = j; n < matrix[m].size(); n++) {
          //adding one to offset 0 based indexing
          area = (m - i + 1) * (n - j + 1);
          if (area  > maxsize) {
            //need to make sure it all contains 1
            if (AllOnesMatrix (matrix, i, j, m, n) )
              maxsize = area;
          }
        }
      }
    }
  }
  return maxsize;
}

int maximalRectangle1 (vector<vector<char> >& matrix)
{
  if (matrix.empty() ) {
    return 0;
  }
  int n = matrix[0].size();
  vector<int> H (n);
  vector<int> L (n);
  vector<int> R (n, n);
  int ret = 0;
  for (int i = 0; i < matrix.size(); ++i) {
    int left = 0, right = n;
    // calculate L(i, j) from left to right
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == '1') {
        ++H[j];
        L[j] = max (L[j], left);
      }
      else {
        left = j + 1;
        H[j] = 0;
        L[j] = 0;
        R[j] = n;
      }
    }
    // calculate R(i, j) from right to right
    for (int j = n - 1; j >= 0; --j) {
      if (matrix[i][j] == '1') {
        R[j] = min (R[j], right);
        ret = max (ret, H[j] * (R[j] - L[j]) );
      }
      else {
        right = j;
      }
    }
  }
  return ret;
}

int main()
{
  /*
  vector<vector<char> > foo (vector<char> {'0', '1', '1', '0', '1'},
                             vector<char> {'1', '1', '0', '1', '0'},
                             vector<char> {'0', '1', '1', '1', '0'},
                             vector<char> {'1', '1', '1', '1', '0'},
                             vector<char> {'1', '1', '1', '1', '1'},
                             vector<char> {'0', '0', '0', '0', '0'});
  cout << "max rectangle is " << maximalRectangle (foo) << endl;
  */
}


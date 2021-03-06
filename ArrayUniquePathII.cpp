/*
  A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

  The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

  How many possible unique paths are there?


  Above is a 3 x 7 grid. How many possible unique paths are there?

  Note: m and n will be at most 100.

*/
#include <queue>
#include <iostream>
#include <vector>


using namespace std;

struct P {
  int x;
  int y;
  P() : x(), y() {};
  P (int x, int y) : x (x), y (y) {};
};

//BFS
int uniquePathsI (int m, int n)
{
  int path = 0;
  queue<P> q;
  q.push (P (0, 0) );
  while (!q.empty() ) {
    P p = q.front();
    q.pop();
    //move down
    if (p.x + 1 <= m - 1) {
      if (p.x + 1 == m - 1 && p.y == n - 1)
        path++;
      else {
        q.push (P (p.x + 1, p.y) );
      }
    }
    //move right
    if (p.y + 1 <= n - 1) {
      if (p.x == m - 1 && p.y + 1 == n - 1)
        path++;
      else {
        q.push (P (p.x, p.y + 1) );
      }
    }
  }
  return path;
}

void uniquePathsHelper (int x, int y, int m, int n, int& path)
{
  if (x == m - 1 && y == n - 1) {
    path++;
    return;
  }
  if (x > m - 1 && y > n - 1)
    return;
  if (x < m - 1) {
    uniquePathsHelper (x + 1, y, m, n, path);
  }
  if (y < n - 1) {
    uniquePathsHelper (x, y + 1, m, n, path);
  }
}

//DFS
int uniquePathsII (int m, int n)
{
  int path = 0;
  uniquePathsHelper (0, 0, m, n, path);
  return path;
}

/*An easy problem, for every location in the grid, the number of path getting here is the sum of the left location and the up location. From the start the path number is only 1. And for the top row and first column,  the number is also 1. Then only loop can solve the problem.
 */
int uniquePaths (int m, int n)
{
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  int** arr = new int* [m];
  for (int i = 0; i < m; i++) {
    arr[i] = new int[n];
  }
  arr[0][0] = 1;
  for (int i = 0; i < m; i++) {
    arr[i][0] = 1;
  }
  for (int i = 0; i < n; i++) {
    arr[0][i] = 1;
  }
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
    }
  }
  int ret = arr[m - 1][n - 1];
  for (int i = 0; i < m; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  return ret;
}

int uniquePathsWithObstacles (vector<vector<int> >& obstacleGrid)
{
  int m = obstacleGrid.size();
  if (m < 1)
    return 0;
  int n = obstacleGrid[0].size();
  if (n < 1)
    return 0;
  if (obstacleGrid[0][0] == 1)
    return 0;
  int** arr = new int* [m];
  for (int i = 0; i < m; i++) {
    arr[i] = new int[n];
  }
  arr[0][0] = 1;
  //fill up rows
  for (int i = 1; i < m; i++) {
    if (obstacleGrid[i][0] == 0)
      arr[i][0] = 1;
    else {
      for (int j = i; j < m; j++)
        arr[j][0] = 0;
      break;
    }
  }
  //fill up columns
  for (int i = 1; i < n; i++) {
    if (obstacleGrid[0][i] == 0)
      arr[0][i] = 1;
    else {
      for (int j = i; j < n; j++)
        arr[0][j] = 0;
      break;
    }
  }
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      int top = (obstacleGrid[i - 1][j] == 1) ? 0 : arr[i - 1][j];
      int left = (obstacleGrid[i][j - 1] == 1) ? 0 : arr[i][j - 1];
      arr[i][j] = (obstacleGrid[i][j] == 1) ? 0 : (top + left);
    }
  }
  int ret = arr[m - 1][n - 1];
  for (int i = 0; i < m; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  return ret;
}

int main()
{
  vector<vector<int> > board;
  board.push_back (vector<int> {0, 0});
  board.push_back (vector<int> {0, 0});
  cout << uniquePathsWithObstacles (board) << endl;
}

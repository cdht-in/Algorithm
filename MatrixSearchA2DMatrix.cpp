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

#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
	int m = matrix.size();
	if(m == 0)
		return false;
	int n = matrix[0].size();
	
	int l = 0;
	int r = m * n - 1;
	
	while(l <= r)
	{
		int mid = (l + r) / 2;
		int i = mid / n;
		int j = mid % n;
		if(matrix[i][j] == target)
			return true;
		else if(matrix[i][j] < target)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	
	return false;
}

int main()
{
	
	
	
}
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
#include <vector>

using namespace std;


vector<vector<int> > generateMatrix(int n) {
	vector<vector<int> > mat(n,vector<int>(n,0));
	if(n == 0)
		return mat;
	if(n == 1)
	{
		mat[0][0] = 1;
		return mat;
	}
	//if n is even, the final index is (n / 2, n / 2 - 1), otherwise it is (n / 2, n/2)
	int finalI = 0;
	int finalJ = 0;
	if(n % 2 == 0)
	{
		finalI = n / 2;
		finalJ = n / 2 - 1;
	}
	else
	{
		finalI = n / 2;
		finalJ = n / 2;	
	}
	
	int i = 0;
	int j = 0;
	int seq = 1;
	while(1)
	{
		//move right
		while(j < n && mat[i][j] == 0)
		{
			mat[i][j++] = seq++;
		}
		j--;
		i++;
		
		if(i == finalI && j == finalJ)
		{
			mat[i][j] = seq;
			break;
		}
		
		//move down
		while(i < n && mat[i][j] == 0)
		{
			mat[i++][j] = seq++;
		}
		i--;
		j--;
		
		if(i == finalI && j == finalJ)
		{
			mat[i][j] = seq;
			break;
		}
		
		//move left
		while(j >= 0 && mat[i][j] == 0)
		{
			mat[i][j--] = seq++;
		}
		j++;
		i--;
		
		if(i == finalI && j == finalJ)
		{
			mat[i][j] = seq;
			break;
		}
		
		//move up
		while(i >= 0 && mat[i][j] == 0)
		{
			mat[i--][j] = seq++;
		}
		i++;
		j++;
		
		if(i == finalI && j == finalJ)
		{
			mat[i][j] = seq;
			break;
		}
		
	}
	
	return mat;
	
}

int main()
{
	
	
}
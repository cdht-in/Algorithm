/*
	
	Given an NxN matrix of positive and negative integers, write code to find the submatrix with the largest possible sum.

*/

#include <vector>
#include <iostream>
#include <climits>


using namespace std;


//brute force O(n^6)
int maxSum(vector<vector<int> >& mat)
{
	int sum = INT_MIN;
	int n = mat.size();
	
	//a,b are the topleft corner
	for(int a = 0; a < n; a++)
	{
		for(int b = 0; b < n; b++)
		{
			//c,d are the bottomright corner
			for(int c = a; c < n; c++)
			{
				for(int d = b; d < n; d++)
				{
					int subSum = 0;
					for(int e = a; e <= c; e++)
					{
						for(int f = b; f <= d; f++)
						{
							subSum += mat[e][f];	
						}
					}
					
					if(subSum > sum)
					{
						//cout << to_string(subSum) + " at (" + to_string(a) + " , " + to_string(b) + ") and (" + to_string(c) + " , " + to_string(d) + ")" << endl;
						sum = subSum;
					}
					
				}
			}
			
		}
	}
	
	return sum;
}

//O(n^4) with memorization
//http://www.hawstein.com/posts/20.12.html
int maxSumI(vector<vector<int> >& mat)
{
	int sum = INT_MIN;
	int n = mat.size();
	
	//the area sum for (0,0) and (i,j)
	vector<vector<int> > areaSum(n + 1,vector<int>(n + 1,0));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			areaSum[i][j] = areaSum[i - 1][j] + areaSum[i][j - 1] - areaSum[i - 1][j - 1] + mat[i - 1][j - 1];
			cout << areaSum[i][j] << " ";
		}
		cout << endl;
	}
	
	//a,b are the topleft corner
	for(int a = 0; a <= n; a++)
	{
		for(int b = 0; b <= n; b++)
		{
			//c,d are the bottomright corner
			for(int c = a; c <= n; c++)
			{
				for(int d = b; d <= n; d++)
				{
					int subSum = areaSum[c][d] - areaSum[a][d] - areaSum[c][b] + areaSum[a][b];			
					
					if(subSum > sum)
					{
						sum = subSum;
					}
				}
			}
			
		}
	}
	
	return sum;
}


//O(n^3) with max subarray problem
//http://prismoskills.appspot.com/lessons/Dynamic_Programming/Chapter_07_-_Submatrix_with_largest_sum.jsp
int maxSumII(vector<vector<int> >& mat)
{
	int n = mat.size();
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		vector<int> vec(n,0);
		for(int j = i; j < n; j++)
		{
			//combine all row between col i and col j into 1-D array
			for(int k = 0; k < n; k++)
			{
				vec[k] += mat[k][j];
			}
			
			int subMax = 0;
			//find the max subarray on the vec
			
			for(int k = 0; k < n; k++)
			{
				if(vec[k] >= vec[k] + subMax)
					subMax = vec[k];
				else
					subMax += vec[k];
				
				if(subMax > max)
					max = subMax;
			}
			
		}
	}
	
	return max;
}

int main()
{
	vector<vector<int> > mat;
	mat.push_back(vector<int>({1,-1,1}));
	mat.push_back(vector<int>({1,-1,1}));
	mat.push_back(vector<int>({1,1,-1}));
	
	cout << maxSumII(mat) << endl;
	
}
/*
	
Medium Submatrix Sum

15% Accepted
Given an integer matrix, find a submatrix where the sum of numbers is zero. Your code should return the coordinate of the left-up and right-down number.

Have you met this question in a real interview? Yes
Example
Given matrix

[
  [1 ,5 ,7],
  [3 ,7 ,-8],
  [4 ,-8 ,9],
]
return [(1,1), (2,2)]

Challenge
O(n3) time.
	
*/

#include "../commonHeader.h"

//hash pair
template <class T>
inline void hash_combine(std::size_t & seed, const T & v)
{
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std
{
  template<typename S, typename T> struct hash<pair<S, T>>
  {
    inline size_t operator()(const pair<S, T> & v) const
    {
      size_t seed = 0;
      ::hash_combine(seed, v.first);
      ::hash_combine(seed, v.second);
      return seed;
    }
  };
}

//O(n^4)
vector<vector<int> > submatrixSum(vector<vector<int> >& matrix) 
{	
	int m = matrix.size();
	int n = matrix[0].size();
	
	unordered_map<pair<int,int>, int> subsum;
	//bottom right corner
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int sum = 0;
			for(int a = 0; a <= i; a++)
			{
				for(int b = 0; b <= j; b++)
				{
					sum += matrix[a][b];
				}
			}
			subsum[make_pair(i,j)] = sum;
		}
	}
	
	vector<vector<int> > ret;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int a = i; a < m; a++)
			{
				for(int b = j; b < n; b++)
				{
					int topLeft = (i >= 1 && j >= 1)? subsum[make_pair(i - 1, j - 1)] : 0;
					int left = (j >= 1)? subsum[make_pair(a,j - 1)] : 0;
					int top = (i >= 1)? subsum[make_pair(i - 1,b)] : 0;
					int sum = subsum[make_pair(a,b)] + topLeft - left - top;
					if(sum == 0)
					{
						vector<int> topLeftCorner;
						topLeftCorner.push_back(i);
						topLeftCorner.push_back(j);
						vector<int> bottomRightCorner;
						bottomRightCorner.push_back(a);
						bottomRightCorner.push_back(b);
						
						ret.push_back(topLeftCorner);
						ret.push_back(bottomRightCorner);
						
						return ret;
					}
					
				}
			}
		}
	}
	
	return ret;
}

//O(n^3)
vector<vector<int> > submatrixSumI(vector<vector<int> >& matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int> > fromTop(m,vector<int>(n,0));
	for(int i = 0; i < n; i++)
	{		
		for(int j = 0; j < m; j++)
		{
			fromTop[j][i] = (j == 0)? matrix[j][i] : fromTop[j - 1][i] + matrix[j][i];
		}
	}
	
	for(int top = 0; top < m; top++)
	{
		for(int bottom = top; bottom < m; bottom++)
		{
			unordered_map<int,int> subSum;
			//take care of [[0]] case
			subSum[0] = -1;
			int sum = 0;
			int rowSum = 0;
			for(int col = 0; col < n; col++)
			{
				rowSum += (top == 0)? fromTop[bottom][col] : fromTop[bottom][col] - fromTop[top - 1][col];
				//rowSum - x = 0 => x = rowSum
				if(subSum.find(rowSum) != subSum.end())
				{
					vector<vector<int> > ret;
					ret.push_back(vector<int>({top,subSum[rowSum] + 1}));
					ret.push_back(vector<int>({bottom,col}));
					return ret;
				}
				
				//save the col
				subSum[rowSum] = col;
			}
		}
	}
	
	return vector<vector<int> >();
	
}


int main()
{
	vector<vector<int> > mat;
	mat.push_back(vector<int>({1,5,7}));
	mat.push_back(vector<int>({3,7,-8}));
	mat.push_back(vector<int>({4,-8,9}));
	
	vector<vector<int> > ret = submatrixSum(mat);
	for(auto i : ret)
	{
		for(auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}
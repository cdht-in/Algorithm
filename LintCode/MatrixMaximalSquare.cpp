/*
	
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

Have you met this question in a real interview? Yes
Example
For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
	
*/

#include "../commonHeader.h"

int maxSquare(vector<vector<int> > &matrix) 
{
	if(matrix.size() < 1)
		return 0;
	
	int m = matrix.size();
	int n = matrix[0].size();
	
	vector<vector<int> > heights(matrix);
	
	for(int i = 1; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(matrix[i][j] == 1 && matrix[i][j] == matrix[i - 1][j])
			{
				heights[i][j] = heights[i - 1][j] + 1;
			}
		}
	}
	
	/*
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << heights[i][j] << " ";
		}
		cout << endl;
	}
	*/
		
	int max = 0;
	for(int i = 0; i < m; i++)
	{
		vector<int> st;
		for(int j = 0; j <= n;)
		{
			int h = (j == n)? -1 : heights[i][j];
			if(st.empty() || h >= heights[i][st.back()])
			{
				st.push_back(j);
				j++;
			}
			else
			{
				//compute the area for each square
				int index = st.back();
				st.pop_back();
				int width = (st.size() == 0)? j - 0 : j - st.back() - 1;
				int min = std::min(heights[i][index],width);
				max = std::max(max,min * min);
			}	
		}		
	}
	return max;
}

int main()
{
	vector<vector<int> > mat = {{0,1,0,1,1,0},{1,0,1,0,1,1},{1,1,1,1,1,0},{1,1,1,1,1,1},{0,0,1,1,1,0},{1,1,1,0,1,1}};
	cout << maxSquare(mat) << endl;
}
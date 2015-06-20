
/*
	Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

*/

#include <vector>
#include <iostream>

using namespace std;

int maximalRectangle(vector<vector<char> > &matrix) {
	if(matrix.size() == 0)
		return 0;
	int m = matrix.size();
	int n = matrix[0].size();
	
	//first turn this problem into the largest histogram problem
	//find the height for each cell
	
	vector<vector<int> > height(m,vector<int>(n,0));
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			//last row
			if(i == 0)
			{
				height[i][j] = (matrix[i][j] != '0')? 1 : 0;
				continue;
			}
			
			if(matrix[i][j] != '0')
			{
				height[i][j] = height[i - 1][j] + 1;
			}
			else
			{
				height[i][j] = 0;
			}
		}
	}
	
	int max = -1;
	//now solve the largest histogram problem on each row
	for(int i = 0; i < m; i++)
	{
		vector<int> st;
		
		for(int j = 0; j <= n;)
		{
			int h = (j == n)? -1 : height[i][j];
			
			if(st.size() == 0 || h >= height[i][st.back()])
			{
				st.push_back(j);
				j++;
			}
			else
			{
				int top = st.back();
				st.pop_back();
				int w = (st.size() == 0)? j : j - 1 - st.back();
				int area = height[i][top] * w;
				max = (max > area) ? max : area;
			}
		}
	}
	return max;
}

int main(){
	vector<vector<char> > matrix;
	
	vector<char> row;
	row.push_back('0');
	row.push_back('1');
	
	matrix.push_back(row);
	
	cout << maximalRectangle(matrix) << endl;
	
	
}
/*

	Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
	
*/

#include <vector>

using namespace std;


void setZeroes(vector<vector<int> > &matrix) {
	int m = matrix.size();
	if(m == 0)
		return;
	int n = matrix[0].size();
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(matrix[i][j] == 0)
			{
				matrix[i][j] = -999;
				for(int k = 0; k < n; k++)
				{
					if(matrix[i][k] != 0)
						matrix[i][k] = -999;
				}
				
				for(int k = 0; k < m; k++)
				{
					if(matrix[k][j] != 0)
						matrix[k][j] = -999;
				}
			}
		}
	}
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(matrix[i][j] == -999)
				matrix[i][j] = 0;
		}
	}
}


int main(){
	
	
}
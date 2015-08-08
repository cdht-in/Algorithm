/*
	
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Have you met this question in a real interview? Yes
Example
Given a matrix

[
  [1,2],
  [0,3]
],
return [ [0,2], [0,0] ]

Challenge
Did you use extra space? A straight forward solution using O(mn) space is probably a bad idea. A simple improvement uses O(m + n) space, but still not the best solution. Could you devise a constant space solution?
	
*/

#include "../commonHeader.h"

//O(mn) in time and O(n + m) space
void setZeroes(vector<vector<int> > &matrix)
{
	unordered_set<int> row;
	unordered_set<int> col;
	for(int i = 0 ; i < matrix.size(); i++)
	{
		for(int j = 0; j < matrix[0].size(); j++)
		{
			if(matrix[i][j] == 0)
			{
				row.insert(i);
				col.insert(j);
			}
		}
	}
	
	for(int i : row)
	{
		for(int j = 0; j < matrix[0].size(); j++)
		{
			matrix[i][j] = 0;
		}
	}
	
	for(int i : col)
	{
		for(int j = 0; j < matrix.size(); j++)
		{
			matrix[j][i] = 0;
		}
	}
}

//O(mn) in time, and use the first row and first col to store
void setZeroesI(vector<vector<int> > &matrix)
{
	if(matrix.size() == 0)
		return;
	
	int row = matrix.size(), col = matrix[0].size();  
	bool zerorow=false, zerocol=false;  
	for(int i = 0; i< col; i++)  
	  if(matrix[0][i] ==0)  
	    zerorow = 1;  
	 for(int i = 0; i< row; i++)  
	   if(matrix[i][0] ==0)  
	     zerocol=1;
	 
	 for(int i =1; i < row; i++)  
	   for(int j = 1; j<col; j++)  
	     if(matrix[i][j] ==0)  
	     {  
	       matrix[0][j] =0;  
	       matrix[i][0] =0;  
	     }  
	 for(int i =1; i < row; i++)  
	   for(int j = 1; j<col; j++)  
	     if(matrix[i][0] ==0 || matrix[0][j] ==0)  
	       matrix[i][j] =0;  
	 if(zerorow ==1)  
	   for(int i =0; i< col; i++)  
	     matrix[0][i] =0;  
	 if(zerocol==1)  
	   for(int i =0; i< row; i++)  
	     matrix[i][0] =0;          
}

int main()
{
	
}


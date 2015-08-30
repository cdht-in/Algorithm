/*
	
Given n x m non-negative integers representing an elevation map 2d where the area of each cell is 1 x 1, compute how much water it is able to trap after raining.

*/

#include "../commonHeader.h"

void trapRainWaterHelper(vector<int*> &heights,vector<int*> &water) 
{
	if(heights.size() <= 2)
		return;
	
	int lHeight = 0;
	int width = 1;
	//index to volumn
	unordered_map<int,int> tmpSum;
	for(int i = 0; i < heights.size(); i++)
	{
		if(*heights[i] < lHeight)
		{
			tmpSum[i] = (lHeight - *heights[i]) * width;
		}
		else
		{
			for(auto& iterator : tmpSum)
			{
			   	*(water[iterator.first]) = iterator.second;
			}
			
			tmpSum.clear();
			lHeight = *heights[i];
		}
	}
	
	int rHeight = 0;
	tmpSum.clear();
	for(int i = heights.size() - 1; i >= 0; i--)
	{
		//NOTE here for case like [100,0,100], the container could be counted twice
		// <= here awoids this situation
		if(*heights[i] <= rHeight)
		{
			tmpSum[i] = (rHeight - *heights[i]) * width;
		}
		else
		{
			for(auto& iterator : tmpSum)
			{
				*(water[iterator.first]) = iterator.second;
			}
			
			tmpSum.clear();
			rHeight = *heights[i];
		}
	}
}


//this approach may seem to work, but it fails
int trapRainWater(vector<vector<int> > &heights) 
{
	int m = heights.size();
	int n = heights[0].size();
	
	if(m * n < 9)
		return 0;
	
	vector<vector<int> > leftRight(m,vector<int>(n,0));
	vector<vector<int> > topDown(m,vector<int>(n,0));
	
	vector<int*> row(n,0);
	vector<int*> rowPointer(n,0);
	for(int i = 0; i < m; i++)
	{		
		for(int j = 0; j < n; j++)
		{
			row[j] = &heights[i][j];
			rowPointer[j] = &leftRight[i][j];
		}
		
		trapRainWaterHelper(row,rowPointer);
	}
	
	vector<int*> col(m,0);
	vector<int*> colPointer(m,0);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			col[j] = &heights[j][i];
			colPointer[j] = &topDown[j][i];
		}
		
		trapRainWaterHelper(col,colPointer);
	}
	
	int sum = 0;
	for(int i = 0; i < m; i++)
	{		
		for(int j = 0; j < n; j++)
		{
			sum += std::min(leftRight[i][j],topDown[i][j]);
		}
	}
	
	for(int i = 0; i < m; i++)
	{		
		for(int j = 0; j < n; j++)
		{
			cout << leftRight[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
	
	for(int i = 0; i < m; i++)
	{		
		for(int j = 0; j < n; j++)
		{
			cout << topDown[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	return sum;
}

int main()
{
	vector<vector<int> > heights = {{12,13,0,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13}};
	//{{1,1,1},{1,1,1},{1,1,1}};
	cout << trapRainWater(heights) << endl;
}
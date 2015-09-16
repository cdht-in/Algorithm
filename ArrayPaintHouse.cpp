/*
	
There are a row of houses, each house can be painted with three colors red, 
blue and green. The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.
You have to paint the houses with minimum cost. How would you do it?
Note: Painting house-1 with red costs different from painting house-2 with red. 
The costs are different for each house and each color.
	
*/

#include "./commonHeader.h"

enum Color
{
	red,
	blue,
	green,
};

//O(n^2)
int PaintHouse(vector<unordered_map<int,int> >& houses)
{
	//paint i house color j
	int numOfColor = 3;
	vector<vector<int> > dp(houses.size(),vector<int>(numOfColor,INT_MAX));

	for(int i = 0; i < houses.size(); i++)
	{
		for(int j = 0; j < numOfColor; j++)
		{
			if(i == 0)
			{
				dp[i][j] = houses[i][j];
				continue;
			}
			
			//if the i house is painted j, then the previous house can't be painted j
			int prevCost = INT_MAX;
			
			for(int k = 0; k < numOfColor; k++)
			{
				if(k != j)
					prevCost = std::min(prevCost,dp[i - 1][k]);
			}
			
			dp[i][j] = std::min(dp[i][j],prevCost + houses[i][j]);
		}
	}
	
	int min = INT_MAX;
	for(int i = 0; i < numOfColor; i++)
	{
		min = std::min(min,dp[houses.size() - 1][i]);
	}
	
	return min;
}

int main()
{
	vector<unordered_map<int,int> > houses;
	houses.push_back(unordered_map<int,int>({{red,1},{blue,2},{green,3}}));
	houses.push_back(unordered_map<int,int>({{red,2},{blue,3},{green,1}}));
	houses.push_back(unordered_map<int,int>({{red,3},{blue,1},{green,2}}));
	cout << PaintHouse(houses) << endl;
}
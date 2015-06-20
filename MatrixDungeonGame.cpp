/*

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
	
*/

#include <vector>
#include <climits>
#include <iostream>


using namespace std;


//starting at the bottom-right and walk reversely, brute force
void calculateMinimumHPHelper(vector<vector<int> > &dungeon, int i, int j,int curHP,int& minHP) {
	
	if(dungeon[i][j] <= 0)
	{
		curHP -= dungeon[i][j];
	}
	else
	{
		//excessive HP
		if(curHP - dungeon[i][j] >= 0)
		{
			curHP -= dungeon[i][j];
		}
		//else => don't need the postive HP from this cell since we are finding the minimal
	}
	
	if(i == 0 && j == 0)
	{
		minHP = (minHP < curHP)? minHP : curHP;
		return;
	}
	
	//go up
	if(i >= 1)
	{
		calculateMinimumHPHelper(dungeon, i - 1, j,curHP,minHP);
	}
	
	//go left
	if(j >= 1)
	{
		calculateMinimumHPHelper(dungeon, i, j - 1,curHP,minHP);
	}
}

int calculateMinimumHP(vector<vector<int> > &dungeon) {
	if(dungeon.size() == 0)
		return 0;
	int m = dungeon.size();
	int n = dungeon[0].size();
	int minHP = INT_MAX;
	calculateMinimumHPHelper(dungeon,m - 1, n - 1, 1,minHP);
	return minHP;
}

//dp
int calculateMinimumHPI(vector<vector<int> > &dungeon) {

	if(dungeon.size() == 0)
		return 0;
	int m = dungeon.size();
	int n = dungeon[0].size();
	vector<vector<int> > dp(m,vector<int>(n,0));
	
	int curHP = 1;
	for(int i = n - 1; i >= 0; i--)
	{
		if(curHP - dungeon[m - 1][i] <= 0)
		{
			curHP = 1;
		}
		else
		{
			curHP -= dungeon[m - 1][i];
		}
		dp[m - 1][i] = curHP;	
	}
	
	curHP = 1;
	for(int i = m - 1; i >= 0; i--)
	{
		if(curHP - dungeon[i][n - 1] <= 0)
		{
			curHP = 1;
		}
		else
		{
			curHP -= dungeon[i][n - 1];	
		}
		dp[i][n - 1] = curHP;	
	}
	
	for(int i = m - 2; i >= 0; i--)
	{
		for(int j = n - 2; j >= 0; j--)
		{
			int curRight = dp[i][j + 1];
			int curBottom = dp[i + 1][j];
			
			//this implies dungeon[i][j] is positive, we only need minimum 1 hp
			if(curRight - dungeon[i][j] <= 0)
			{
				curRight = 1;
			}
			else
			{
				curRight -= dungeon[i][j];
			}
			
			if(curBottom - dungeon[i][j] <= 0)
			{
				curBottom = 1;
			}
			else
			{
				curBottom -= dungeon[i][j];
			}
			dp[i][j] = (curRight < curBottom)? curRight : curBottom;
		}
	}
	
	return dp[0][0];
}

int main()
{
	vector<vector<int> > dungeon;
	vector<int> r1 = {0,-3};
	vector<int> r2 = {-10,0};
	//vector<int> r3 = {10,30,-5};
	dungeon.push_back(r1);
	dungeon.push_back(r2);
	//dungeon.push_back(r3);
	
	cout << calculateMinimumHPI(dungeon) << endl;
	
}
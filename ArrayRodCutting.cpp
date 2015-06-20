#include <vector>
#include <iostream>

using namespace std;

int prices[] = {1,5,8,9,10,17,17,20,24,30};

//recursion O(2^n)
int CutRod(int n)
{
	if(n == 0)
		return 0;
	int max = -1;
	for(int i = 1; i <= n; i++)
	{
		max = std::max(max,prices[i - 1] + CutRod(n - i));
	}
	return max;
}

//top down DP O(n^2)
int CutRodTopDownDP(int n)
{
	static vector<int> rodLen(n,-1);
	
	if(rodLen[n - 1] != -1)
	{
		return rodLen[n];
	}
	
	if(n == 0)
		return 0;
	
	int max = -1;
	
	for(int i = 1; i <= n; i++)
	{
		max = std::max(max, prices[i - 1] + CutRod(n - i));
	}
	
	rodLen[n - 1] = max;
	
	return max;
}


//bottm up DP O(n^2)
int CutRodTopBottomUpDP(int n)
{
	vector<int> rodLen(n + 1,0);
	for(int i = 1; i <= n; i++)
	{
		int max = -1;
		for(int j = 1; j <= i; j++)
		{
			max = std::max(max,prices[j - 1] + rodLen[i - j]);
		}
		rodLen[i] = max;
	}
	return rodLen[n];
}

//bottm up DP with memorizing the cuts O(n^2)
int CutRodTopBottomUpDPWithCuts(int n)
{
	vector<int> rodLen(n + 1,0);
	vector<int> start(n + 1,0);
	for(int i = 1; i <= n; i++)
	{
		int max = -1;
		for(int j = 1; j <= i; j++)
		{
			if(max < prices[j - 1] + rodLen[i - j])
			{
				max = prices[j - 1] + rodLen[i - j];
				//record the cut position
				start[i] = j;
			}
		}
		rodLen[i] = max;
	}
	
	//print the cuts
	int p = n;
	while(p)
	{
		//backtrack the cut position
		cout << start[p] << " ";
		p -= start[p];
	}
	
	return rodLen[n];
	
}

int main()
{
	cout << CutRodTopBottomUpDPWithCuts(4) << endl;
}
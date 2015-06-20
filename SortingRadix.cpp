#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;


//only handle positive number for now, could be added to handle the negative number with a partition first
void RadixSort(vector<int>& vec)
{
	//find the radix
	int max = -1;
	for(int i = 0; i < vec.size(); i++)
	{
		if(vec[i] > max)
			max = vec[i];
	}
	
	int radix = 0;
	while(max > 0)
	{
		radix++;
		max /= 10;
	}
	
	int tmp = 1;
	for(int i = 0; i < radix; i++)
	{
		//counting sort the radix [0,9]
		vector<vector<int> > c(10,vector<int>());
		
		//sort from the least significant number first
		for(int j = 0; j < vec.size(); j++)
		{
			int digit = (vec[j] / tmp) % 10;
			c[digit].push_back(vec[j]);
		}
		
		int p = 0;
		for(int j = 0; j < c.size(); j++)
		{
			for(int k = 0; k < c[j].size(); k++)
			{
				vec[p++] = c[j][k];
			}
		}
		
		tmp *= 10;
	}
}

int main()
{
	vector<int> vec = {2,3,14,5,0,100,22};
	
	RadixSort(vec);
	
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	
}
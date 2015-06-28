#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

vector<vector<int> > KPartition(vector<int>& list, int nPartitions)
{
	vector<vector<int> > ret;
	int partitionSize = (list.size() + 1) / nPartitions;
	int p = list.size() - 1;
	while(p >= 0)
	{
		ret.push_back(vector<int>());
		for(int i = 0; p >= 0 && i < partitionSize; i++)
		{
			int index = (p > 0)? rand() % p : 0;
			ret.back().push_back(list[index]);
			int tmp = list[p];
			list[p] = list[index];
			list[index] = tmp;
			p--;
		}
	}
	return ret;
}


int main()
{
	vector<int> list = {2,3,1,5,6,9,1};
	int k = 2;
	vector<vector<int> > ret = KPartition(list,k);
	for(int i = 0; i < ret.size(); i++)
	{
		for(int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
}
#include <vector>
#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

struct Pair
{
	int x;
	int y;
	int distant;
	Pair(){};
	
	Pair(int x, int y):x(x),y(y),distant(x * x + y * y){};
};

void Swap(Pair& a, Pair& b)
{
	int tmpX = a.x;
	int tmpY = a.y;
	int tmpDistant = a.distant;
	
	a.x = b.x;
	a.y = b.y;
	a.distant = b.distant;
	
	b.x = tmpX;
	b.y = tmpY;
	b.distant = tmpDistant;
}

//Find K closet pairs to the originm, orders statistic O(n)
vector<Pair> KCloestPairs(vector<Pair>& pairs, int k)
{
	vector<Pair> result;
	if(pairs.size() == 0)
		return result;
	
	int p = 0;
	//find k closet pairs
	for(int i = 0; i < k; i++)
	{
		int min = INT_MAX;
		int minIndex = 0;
		
		for(int j = p; j < pairs.size(); j++)
		{
			if(pairs[j].distant < min)
			{
				minIndex = j;
				min = pairs[j].distant;
			}
		}
		
		Swap(pairs[minIndex],pairs[p]);
		p++;		
		result.push_back(pairs[p - 1]);
	}
	
	return result;
}


int main()
{
	vector<Pair> pairs;
	pairs.push_back(Pair (1,1));
	pairs.push_back(Pair (1,2));
	pairs.push_back(Pair (3,3));
	pairs.push_back(Pair (3,1));
	pairs.push_back(Pair (4,6));
	
	int k = 5;
	vector<Pair> result = KCloestPairs(pairs,k);
	for(int i = 0; i < result.size(); i++)
	{
		cout << "( " << result[i].x << " , " << result[i].y << " )" << endl;
	}
}


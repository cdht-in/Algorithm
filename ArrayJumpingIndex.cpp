
#include <vector>
#include <set>
#include <iostream>

using namespace std;

//test if the relative index jumping forms a complete cycle
bool IsCycle(vector<int>& vec)
{
	int index = 0;
	for(int i = 0; i < vec.size(); i++)
	{
		int newIndex = vec[index] + index;
		int size = vec.size();
		
		if(newIndex < 0)
		{
			newIndex = std::abs(newIndex + size) % size;
		}
		
		newIndex %= size;
		
		index = newIndex;
	}
	
	return index == 0;
}

int main()
{
	//2 2 -1
	vector<int> vec = {1}; 
	cout << IsCycle(vec) << endl;
}
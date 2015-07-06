#include <vector>
#include <iostream>

using namespace std;

int MajorityElement(vector<int>& vec)
{
	if(vec.size() == 0)
		throw "empty vector";
	int candidate = vec[0];
	int counter = 0;
	for(int i = 1; i < vec.size(); i++)
	{
		if(counter == 0)
		{
			candidate = vec[i];
		}
		if(vec[i] == candidate)
		{
			counter++;
		}
		else
		{
			counter--;
		}
	}
	
	counter = 0;
	for(int i = 0; i < vec.size(); i++)
	{
		if(vec[i] == candidate)
			counter++;
	}
	
	if(counter < ( vec.size() + 1 ) / 2)
		throw "no majority element";
	return candidate;
}

int main()
{
	vector<int> ret = {1,2,3};
	cout << MajorityElement(ret) << endl;
}
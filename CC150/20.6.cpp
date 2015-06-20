/*

	Describe an algorithm to find the largest 1 million numbers in 1 billion numbers. Assume that the computer memory can hold all one billion numbers.

*/

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//here n is 10 and k = 3 to simplify the problem

//naive approach, sort it and select the top k
vector<int> TopKValues(vector<int>& vec, int k)
{
	vector<int> result;
	
	sort(vec.begin(),vec.end());
	
	for(int i = vec.size() - 1; i >= 0 && vec.size() - 1 - i < k; i--)
	{
		result.push_back(vec[i]);
	}
	
	return result;
}

//apprach 1, using a heap, O(nlog(n)) in time and O(n) in space
vector<int> TopKValuesI(vector<int>& vec, int k)
{
	priority_queue<int> q;
	
	vector<int> result;
	
	for(int i = 0; i < vec.size(); i++)
	{
		q.push(vec[i]);
	}
	
	for(int i = 0; i < k && (q.empty() == false); i++)
	{
		result.push_back(q.top());
		q.pop();
	}
	
	return result;
}

//apprach II, order statistic, O(n) in time and O(1) in space, this is good when k is far less than n
//if k == n, sort it is better since this approach would be O(n^2) but sorting is O(nlogn)
vector<int> TopKValuesII(vector<int>& vec, int k)
{
	vector<int> result;
	
	for(int i = 0; i < k; i++)
	{
		int maxIndex = 0;
		
		for(int j = 0; j < vec.size() - result.size(); j++)
		{
			if(vec[j] > vec[maxIndex])
			{
				maxIndex = j;
			}	
		}
		
		//swap the max to the end
		int tmp = vec[maxIndex];
		vec[maxIndex] = vec[vec.size() - result.size() - 1];
		vec[vec.size() - result.size() - 1] = tmp;
		
		result.push_back(tmp);
	}
	
	return result;
}

int main()
{
	vector<int> vec = {2,1,3,5,4,6,7,8,9,0};
	int k = 3;
	
	vector<int> result = TopKValues(vec,k);
	
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	
	cout << endl;
	
}



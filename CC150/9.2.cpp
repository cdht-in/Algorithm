/*

	Write a method to sort an array of strings so that all the anagrams are next to each other.

*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

//O(n^2logn)
void SortAnagrams(vector<string>& vec)
{
	unordered_map<string,vector<string> > map;
	
	//O(n^2logn)
	for(int i = 0; i < vec.size(); i++)
	{
		string tmp = vec[i];
		
		sort(tmp.begin(),tmp.end());
		
		if(map.find(tmp) == map.end())
		{
			map[tmp] = vector<string>();
		}
		
		map[tmp].push_back(vec[i]);
	}
	
	//O(n)
	int p = 0;
	for(auto it = map.begin(); it != map.end(); it++)
	{
		for(int j = 0; j < it->second.size(); j++)
		{
			vec[p++] = it->second[j];
		}
	}
}


//apprach ii O(n^2 logn)
bool cmp(string s1, string s2)
{
    sort(&s1[0], &s1[0]+s1.length());
    sort(&s2[0], &s2[0]+s2.length());
    return s1 < s2;
}

void SortAnagramsI(vector<string>& vec)
{
	sort(vec.begin(),vec.end(),cmp);
}


int main()
{
	vector<string> vec = {"abc","dd","acb","bac","cc","23"};
	
	SortAnagramsI(vec);

	for(int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;	
}
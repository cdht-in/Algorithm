/*
  Write a function to find the longest common prefix string amongst an array of strings.

*/
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <climits>


using namespace std;


//O(n^2)
string longestCommonPrefix(vector<string> &vec) {
    if (vec.size() < 1)
      return "";
	if(vec.size() == 1)
		return vec[0];
	
	int min = INT_MAX;
	int longest = 0;
	for(int i = 0; i < vec[0].size(); i++)
	{
		for(int j = 1; j < vec.size(); j++)
		{
			if(vec[0][i] != vec[j][i])
			{
				return vec[0].substr(0,longest);
			}
		}
		longest++;
	}
	return vec[0].substr(0,longest);
}

int main()
{
  vector<string> vec;
  vec.push_back ("a");
  vec.push_back ("b");
  
  cout << longestCommonPrefix (vec) << endl;
}

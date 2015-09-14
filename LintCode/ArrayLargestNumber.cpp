/*
	
Medium Largest Number

17% Accepted
Given a list of non negative integers, arrange them such that they form the largest number.

Have you met this question in a real interview? Yes
Example
Given [1, 20, 23, 4, 8], the largest formed number is 8423201.

Note
The result may be very large, so you need to return a string instead of an integer.

*/

#include "../commonHeader.h"

using namespace std;

//NOTE here that, if s is passed in as a reference, better gaurd it with const
bool myfunction (const string& i,const string& j) 
{
	return (i + j < j + i);
}

string largestNumber(vector<int> &num) 
{	
	vector<string> strings;
	vector<vector<string> > buckets(10,vector<string>());
	
	for(int i = 0; i < num.size(); i++)
	{
		string s = to_string(num[i]);
		buckets[s[0] - '0'].push_back(s);
	}
		
	for(int i = 0; i < buckets.size(); i++)
	{
		sort(buckets[i].begin(),buckets[i].end(),myfunction);
	}
	
	string s = "";
	for(int i = buckets.size() - 1; i >= 0; i--)
	{
		for(int j = buckets[i].size() - 1; j >= 0; j--)
		{
			s += buckets[i][j];
		}
	}
	
	//trim the leading zeros
	int i = 0;
	while(i < s.size() && s[i] == '0')
	{
		i++;
	}
	
	return (i == s.size())? "0" : s;
}

int main()
{
	vector<int> num = {41,23,87,55,50,53,18,9,39,63,35,33,54,25,26,49,74,61,32,81,97,99,38,96,22,95,35,57,80,80,16,22,17,13,89,11,75,98,57,81,69,8,10,85,13,49,66,94,80,25,13,85,55,12,87,50,28,96,80,43,10,24,88,52,16,92,61,28,26,78,28,28,16,1,56,31,47,85,27,30,85,2,30,51,84,50,3,14,97,9,91,90,63,90,92,89,76,76,67,55};
	cout << largestNumber(num) << endl;
}
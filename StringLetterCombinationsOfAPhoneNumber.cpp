/*
	
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

void letterCombinationsHelper(vector<string>& result,string& digits,string s, int start,map<char,string>& cMap)
{
	if(start >= digits.size())
	{
		result.push_back(s);
		return;
	}
	
	for(int j = 0; j < cMap[digits[start]].size(); j++)
	{
		letterCombinationsHelper(result,digits,s + cMap[digits[start]][j],start + 1,cMap);
	}		
}
 
vector<string> letterCombinations(string digits) {
	vector<string> result;
	if(digits.size() == 0)
		return result;
	
	map<char,string> cMap;
	cMap['1'] = "1";	
	cMap['2'] = "abc";
	cMap['3'] = "def";	
	cMap['4'] = "ghi";
	cMap['5'] = "jkl";
	cMap['6'] = "mno";
	cMap['7'] = "pqrs";
	cMap['8'] = "tuv";
	cMap['9'] = "wxyz";
	cMap['0'] = "0";
	
	letterCombinationsHelper(result,digits,"",0,cMap);
	return result;
}
	
int main()
{
	string s = "13";
	vector<string> vec = letterCombinations(s);
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}	
}
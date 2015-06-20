/*
	
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

	
*/

#include <string>
#include <vector>

using namespace std;

//O(n) time and space
bool isValid(string s) {
	if(s.size() == 0)
		return false;
	vector<char> st;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			st.push_back(s[i]);
		else
		{
			if(st.size() == 0)
				return false;
			
			if(s[i] == ')' && st.back() == '(')
			{
				st.pop_back();
				continue;
			}
			
			if(s[i] == '}' && st.back() == '{')
			{
				st.pop_back();
				continue;
			}
			
			if(s[i] == ']' && st.back() == '[')
			{
				st.pop_back();
				continue;
			}
			return false;
		}
	}
	
	if(st.size() == 0)
		return true;
	return false;
}


//O(n) time and O(1) space
bool isValidI(string s) {
	
	//number of left parentheses
	int nL = 0;
	int MostNested = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '(')
		{
			nL++;
			if(nL > MostNested)
				MostNested = nL;
		}
		else
		{
			//unmatched right parentheses
			if(nL <= 0)
				return false;
			nL--;

		}
	}
	//unmatched left parentheses
	if(nL > 0)
		return false;
	return true;
}


int main(){
	
}
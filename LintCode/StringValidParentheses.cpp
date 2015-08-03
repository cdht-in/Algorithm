/*
	
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

Have you met this question in a real interview? Yes
Example
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
	
*/

#include "../commonHeader.h"

bool isValidParentheses(string& s) 
{
	vector<char> st;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			st.push_back(s[i]);
		}
		else
		{
			if(s[i] == ')' && st.empty() == false && st.back() == '(')
			{
				st.pop_back();
			}
			else if(s[i] == '}' && st.empty() == false && st.back() == '{')
			{
				st.pop_back();
			}
			else if(s[i] == ']' && st.empty() == false && st.back() == '[')
			{
				st.pop_back();
			}
			else
			{
				st.push_back(s[i]);
			}
		}
	}
	
	return st.empty();
}

int main()
{
	
}
/*
	
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;


int longestValidParentheses(string s) {
	if(s.size() <= 1)
		return 0;
	vector<int> st;
	
	int max = 0;
	
	for(int j = 0; j < s.size(); j++)
	{
		if(s[j] == '(')
		{
			st.push_back(j);
		}
		else
		{
			if(st.size() > 0 && s[st.back()] == '(')
			{
				st.pop_back();
				
				int len = 0;
				//valid so far
				if(st.size() == 0)
				{
					len = j + 1;
				}
				else
				{
					len = j - st.back();
				}
				
				max = (max > len)? max: len;
			}
			else
			{
				//this shrinks the invalid region
				st.push_back(j);
			}
		}
	}
	
	return max;
}










































//second implementation
int longestValidParenthesesI(string s) {
	if(s.size() == 0)
		return 0;
	int max = 0;
	int start = -1;
	int end = -1;
	vector<int> st;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '(')
		{
			st.push_back(i);
		}
		else
		{
			if(st.size() > 0 && s[st.back()] == '(')
			{
				int len = 0;
				st.pop_back();
				//valid parens
				if(st.size() == 0)
				{
					len = i + 1;
				}
				else
				{
					len = i - st.back();
				}
				
				if(len > max)
				{
					max = len;
					start = i - len;
					end = i;
				}
			}
			else
			{
				st.push_back(i);
			}
		}
	}
	return max;
}



int main()
{
	string s = ")()())";
	cout << longestValidParentheses(s) << endl; 
		
}
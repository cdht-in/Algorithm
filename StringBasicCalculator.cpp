/*

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
	
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int StringToNum(const string& s)
{
	int n = 0;
	for(int i = 0; i < s.size(); i++)
	{
		n *= 10;
		n += (s[i] - '0');
 	}
	return n;
}

int ComputeEquation(const vector<string>& rpn)
{
	vector<int> result;
	for(int i = 0; i < rpn.size(); i++)
	{
		if(rpn[i] == "+" || rpn[i] == "-")
		{
			int b = result.back();
			result.pop_back();
			int a = result.back();
			result.pop_back();
			
			if(rpn[i] == "+")
			{
				result.push_back(a + b);
			}
			else if(rpn[i] == "-")
			{
				result.push_back(a - b);
			}
		}
		else
		{
			result.push_back(StringToNum(rpn[i]));
		}
	}
	
	//there should be only 1 element left in the stack
	return result[0];
}

//assuming valid expression
int calculate(string s) 
{
	vector<char> op;
	vector<string> reversedPolish;
	
	map<char,int> associate;
	associate['+'] = 1;
	associate['-'] = 1;
	
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	
	for(int l = 0,r = 0; r < s.size(); r++)
	{
		while(r < s.size() && isdigit(s[r]))
			r++;
		
		if(l != r)
		{
			if(r == s.size())
			{
				reversedPolish.push_back(s.substr(l,r - l + 1));
				break;
			}
		
			reversedPolish.push_back(s.substr(l,r - l));
		}
		
		if(s[r] == ')')
		{
			while(op.empty() == false && op.back() != '(')
			{
				reversedPolish.push_back(string(1,op.back()));
				op.pop_back();
			}
		
			if(op.empty() == false)
				op.pop_back();
		}
		//'(' 
		else if(s[r] == '(')
		{
			op.push_back(s[r]);
		}
		//'+' or '-'
		else if(s[r] == '+' || s[r] == '-')
		{
			while(op.empty() == false && associate[op.back()] >= associate[s[r]])
			{
				reversedPolish.push_back(string(1,op.back()));
				op.pop_back();
			}
			op.push_back(s[r]);
		}
		
		l = r + 1;
	}
		
	while(op.empty() == false)
	{
		reversedPolish.push_back(string(1,op.back()));
		op.pop_back();
	}
	
	/*
	for(int i = 0; i < reversedPolish.size(); i++)
	{
		cout << reversedPolish[i] << " ";
	}
	cout << endl;
	*/
	
	return ComputeEquation(reversedPolish);
}

int main()
{
	string s = "1-11";
	cout << calculate(s) << endl;
}
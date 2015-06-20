/*
	
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/
#include <stack>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

bool IsOperator(string c)
{
	if(c == "+" || c == "-" || c == "*" || c == "/")
		return true;
	return false;
}

int evalRPN(vector<string> &tokens) {
	if(tokens.size() < 1)
		return 0;
	if(tokens.size() == 1){
		int num = 0;
		istringstream (tokens[0]) >> num;
		return num;
	}
	
	stack<int> st;
	for(int i = 0; i < tokens.size(); i++)
	{
		if(IsOperator(tokens[i]) == false)
		{
			int num = 0;
			istringstream (tokens[i]) >> num;
			st.push(num);
		}
		else
		{
			if(tokens[i] == "+")
			{				
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(a + b);
			}
			else if(tokens[i] == "-")
			{
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(b - a);
			}
			else if(tokens[i] == "*")
			{
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(a * b);
			}
			else
			{
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(b / a);
			}
		}
	}
	return st.top();
}

int main(){
	
	
}
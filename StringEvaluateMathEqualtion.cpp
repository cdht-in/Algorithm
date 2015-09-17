/*
	
	compute  1 + 2 * 3 + 4 = 11

*/

#include "./commonHeader.h"

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


//convert string into reverse polish notation, simple version
//http://en.wikipedia.org/wiki/Shunting-yard_algorithm
vector<string> ShuntingYardAlgorithm(const string& s)
{
	vector<string> output;
	vector<char> op;
	
	map<char,int> precedence;
	precedence['+'] = 1;
	precedence['-'] = 1;
	precedence['*'] = 2;
	precedence['/'] = 2;
	
	for(int i = 0; i < s.size(); i++)
	{
		int j = i + 1;
		while(j < s.size() && isdigit(s[j]))
		{
			j++;
		}
		
		string num = s.substr(i,j - i);
		
		//op
		if(isdigit(s[i]) == false)
		{
			if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
			{
				while(op.size() > 0 &&  precedence[op.back()] >= precedence[s[i]])
				{
					output.push_back(string(1,op.back()));
					op.pop_back();
				}
				op.push_back(s[i]);
			}
			else if(s[i] == '(')
			{
				op.push_back(s[i]);
			}
			else if(s[i] == ')')
			{
				while(op.size() > 0 && op.back() != '(')
				{
					output.push_back(string(1,op.back()));
					op.pop_back();
				}
				
				if(op.size() > 0)
				{
					//pop off the left '('
					op.pop_back();
				}
				else
				{
					cout << "unmatched ')'" << endl;
					return vector<string>();
				}
			}
		}
		else
		{
			output.push_back(num);
		}
	}
	
	//no more tokens
	while(op.size() > 0)
	{
		if(op.back() == '(')
		{
			cout << "left over '('" << endl;
			return vector<string>();
		}
		
		output.push_back(string(1,op.back()));
		op.pop_back();
		
	}
	
	return output;
}


int ComputeEquation(const string& s)
{
	//convert it to rpn first
	vector<string> rpn = ShuntingYardAlgorithm(s);
	
	if(rpn.size() <= 0)
		return INT_MIN;
	/*
	vector<string> rpn = ShuntingYardAlgorithm(s);
	for(int i = 0; i < rpn.size(); i++)
	{
		cout << rpn[i] << " ";
	}
	cout << endl;
	*/
	vector<int> result;
	for(int i = 0; i < rpn.size(); i++)
	{
		if(rpn[i] == "+" || rpn[i] == "-" || rpn[i] == "*" || rpn[i] == "/")
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
			else if(rpn[i] == "*")
			{
				result.push_back(a * b);
			}
			else
			{
				result.push_back(a / b);
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
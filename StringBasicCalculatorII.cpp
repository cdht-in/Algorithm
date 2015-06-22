#include "StringBasicCalculator.cpp"

int calculateI(string s)
{
	vector<char> op;
	vector<string> reversedPolish;
	map<char,int> associate;
	associate['+'] = 1;
	associate['-'] = 1;
	associate['*'] = 2;
	associate['/'] = 2;
	
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
		//operator
		else
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
	string s = "1*11";
	cout << calculateI(s) << endl;
}
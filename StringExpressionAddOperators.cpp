/*
	
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
Credits:
Special thanks to @davidtan1890 for adding this problem and creating all test cases.
	
*/

#include "./commonHeader.h"
#include "./StringEvaluateMathEqualtion.cpp"

void Swap(string& s, int i, int j)
{
	char tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

/*
int Evaluate(string& s)
{
	int sum = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			//sum + 
		}
	}
}
*/

//this algorithm can't take the different priority of '-', '+', and '*' into consideration, thus is wrong
void addOperatorsHelper(string& num, int index,vector<char>& op,int target, string s,int curSum,vector<string>& ret)
{
	if(index >= num.size())
	{
		if(curSum == target)
		{
			ret.push_back(s);
		}
		
		/*
		NO need to compute it in the end
		if(ComputeEquation(s) == target)
		{
			cout << s << endl;
			ret.push_back(s);
		}
		*/
		return;
	}
	
	for(int i = index; i < num.size(); i++)
	{
		Swap(num,i,index);
		//add operators
		if(index > 0)
		{
			/*
			int k = s.size() - 1;
			while(k >= 1 && '0' <= s[k] && s[k] <= '9')
			{
				k--;
			}
			*/
			
			for(int j = 0; j < op.size(); j++)
			{
				//skip the '+' or '*'
				/*
				if((op[j] == '+' || op[j] == '*') && op[j] == s[k])
				{
					continue;
				}
				*/
				
				//addOperatorsHelper(num,index + 1,op,target,s + string(1,op[j]) + string(1,num[index]),ret);
			}			
		}
		else
		{
			//addOperatorsHelper(num,index + 1,op,target,s + string(1,num[index]), curSum + ret);
		}
		
		Swap(num,i,index);
		
		while(i < num.size() - 1 && num[i] == num[i + 1])
			i++;
	}
	
}

/*
void addOperatorsHelperI(vector<string>& ret, int index, int size,const vector<char>& op)
{
	if(index >= size)
	{
		ret.push_back(s);
		return;
	}
	
	for(int i = 0; i < op.size(); i++)
	{
		Swap(num,i,index);
		addOperatorsHelperI(num,index,s + string(1,num[index]),ret);
		Swap(num,i,index);
	}
}
*/

vector<string> addOperators(string num, int target) 
{
	vector<string> ret;
	vector<char> op = {'+','-','*'};
	addOperatorsHelper(num,0,op,target,"",0,ret);
	return ret;
}


//https://leetcode.com/discuss/58535/17-lines-solution-dfs-c
//the use of the variable pv to compute the '*' is epic
void dfs(std::vector<string>& res, const string& num, const int target, string cur, int pos, const long cv, const long pv, const char op) {
        if (pos == num.size() && cv == target) {
            res.push_back(cur);
        } else {
            for (int i=pos+1; i<=num.size(); i++) {
                string t = num.substr(pos, i-pos);
                long now = stol(t);
                if (to_string(now).size() != t.size()) continue;
                dfs(res, num, target, cur+'+'+t, i, cv+now, now, '+');
                dfs(res, num, target, cur+'-'+t, i, cv-now, now, '-');
                dfs(res, num, target, cur+'*'+t, i, (op == '-') ? cv+pv - pv*now : ((op == '+') ? cv-pv + pv*now : pv*now), pv*now, op);
            }
        }
    }

vector<string> addOperatorsI(string num, int target) {
    vector<string> res;
    if (num.empty()) return res;
    for (int i=1; i<=num.size(); i++) {
        string s = num.substr(0, i);
        long cur = stol(s);
        if (to_string(cur).size() != s.size()) continue;
        dfs(res, num, target, s, i, cur, cur, '#');         // no operator defined.
    }

    return res;
}

void addOperatorsIIHelper(vector<string>& ret, string& num, int target, string curString, int index, long curValue, long prevValue, char op)
{
    if (index >= num.size() && curValue == target) 
	{
        ret.push_back(curString);
		return;
    }
	
    for (int i = index; i < num.size(); i++) 
	{
        string secondString = num.substr(index, i - index + 1);
        long now = stol(secondString);
		
		//this skip the case "000"
		if (to_string(now).size() != secondString.size())
			continue;
				
        addOperatorsIIHelper(ret, num, target, curString + "+" + secondString, i + 1, curValue + now, now, '+');
		
        addOperatorsIIHelper(ret, num, target, curString + "-" + secondString, i + 1, curValue - now, now, '-');
		
		/*
        addOperatorsIIHelper(ret, num, target, curString+"*"+secondString, i + 1, (op == '-') ? curValue+prevValue - prevValue*now : ((op == '+') ? curValue-prevValue + prevValue*now : prevValue*now), prevValue*now, op);
		*/
		
		//'*' operator
		int curValueTmp = 0;
		if(op == '-')
		{
			curValueTmp = curValue + prevValue - prevValue * now;
		}
		else if(op == '+')
		{
			curValueTmp = curValue - prevValue + prevValue * now;
		}
		else
		{
			curValueTmp = prevValue * now;
		}
        addOperatorsIIHelper(ret, num, target, curString + "*" + secondString, i + 1, curValueTmp,prevValue * now, op);
    }
}

//similar to work breaks
vector<string> addOperatorsII(string num, int target) 
{
	vector<string> ret;
	for(int i = 0; i < num.size(); i++)
	{
		string curString = num.substr(0,i + 1);
		long curValue = stol(curString);
		
		//this skip the case "000"
		if (to_string(curValue).size() != curString.size())
			continue;
		
		//no operators go before the first number
		addOperatorsIIHelper(ret,num,target,curString,i + 1,curValue,curValue,'#');
	}
	
	return ret;
}

int main()
{
	string num = "123";
	int target = 6;
	vector<string> ret = addOperatorsII(num,target);
	for(auto& i : ret)
	{
		cout << i << endl;
	}
	
}
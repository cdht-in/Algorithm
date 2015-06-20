/*
  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

  For example, given n = 3, a solution set is:

  "((()))", "(()())", "(())()", "()(())", "()()()"
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;


/*
first implementation

//l = appearance of (, r = appearance of )
void generator (vector<string>& ans, string s, int l, int r, int n)
{
  if (l == n) {
    ans.push_back (s.append (n - r, ')') );
    return;
  }
  generator (ans, s + '(', l + 1, r, n);
  if (l > r) generator (ans, s + ")", l, r + 1, n);
}

vector<string> generateParenthesis (int n)
{
  vector<string> ans;
  if (n > 0) generator (ans, "", 0, 0, n);
  return ans;
}

*/

//second implementation
//典型的递归。一步步构造字符串。当左括号出现次数<n时，就可以放置新的左括号。当右括号出现次数小于左括号出现次数时，就可以放置新的右括号。
void generator (vector<string>& ans, string s, int l, int r, int n)
{
  if (l == n) 
  {
	  //NOTE here l == n - r => l + r == 2n
    ans.push_back (s.append (n - r, ')') );
    return;
  }
  
  generator (ans, s + '(', l + 1, r, n);
  
  if (l > r) 
	  generator (ans, s + ")", l, r + 1, n);
}

vector<string> generateParenthesis (int n)
{
  vector<string> ans;
  if (n > 0) 
	  generator (ans, "", 0, 0, n);
  return ans;
}














































void generateParenthesisIHelper(int l, int r, int n,string s)
{
	if(l == n)
	{
		for(int i = r; i < n; i++)
		{
			s += ")";
		}
		cout << s << endl;
		return;
	}
	
	generateParenthesisIHelper(l + 1, r, n, s + "(");
	
	if(l > r)
		generateParenthesisIHelper(l, r + 1, n, s + ")");
	
}

//second implementation
void generateParenthesisI(int n) {
	if(n == 0)
	{
		return;
	} 
	
	generateParenthesisIHelper(0,0,n,"");
}



void generateParenthesisIIHelper(int n, int opened, int closed, string s)
{
	if(opened < n)
		generateParenthesisIIHelper(n, opened + 1, closed,s + "(");
	
	if(closed < opened)
		generateParenthesisIIHelper(n, opened, closed + 1,s + ")");
	
	if(opened == closed && opened == n)
	{
		cout << s << endl;
	}
}

//third implementation
void generateParenthesisII(int n)
{
	generateParenthesisIIHelper(n,0,0,"");
}

int main()
{
  generateParenthesisII(2);
}

/*
  Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

  For "(()", the longest valid parentheses substring is "()", which has length = 2.

  Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

*/

#include <string>
#include <iostream>
#include <stack>

using namespace std;

//longest adjacent parens
int longestValidParentheses (string s)
{
  if (s.size() < 2)
    return 0;
  int p = 1;
  int max = 0;
  while (p < s.size() ) {
    if (s[p - 1] == '(' && s[p] == ')') {
      int i = p;
      int tmp = 2;
      for (i = p + 2; i < s.size() && s[i - 1] == '(' && s[i] == ')'; i += 2)
        tmp += 2;
      max = (max < tmp) ? tmp : max;
      p++;
    }
    else
      p++;
  }
  return max;
}

int longestValidParentheses1 (string s)
{
  int max = 0;
  stack<int> st;
  for (int j = 0; j < s.size(); j++) {
    if (s[j] == '(')
      st.push (j);
    //')'
    else {
      if (!st.empty() && s[st.top()] == '(') {
        st.pop();
	//if st is empty, so far the whole sring is valid, else looking for last place that it was still valid
        int tmp = j - (st.empty() ? (-1) : st.top());
        max = (max > tmp) ? max : tmp;
      }
      else
        st.push (j);
    }
  }
  return max;
}

int main()
{
  string s = "(()";
  cout << longestValidParentheses1 (s) << endl;
}

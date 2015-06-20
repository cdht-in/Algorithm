/*
  check if parens are matching
*/
#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool isValid (string s)
{
  if (s.size() < 2)
    return false;
  std::stack<char> stack;
  for (int i = 0; i < s.size(); i++) {
    //pushing the left paren
    if (s[i] == '{' || s[i] == '(' || s[i] == '[' )
      stack.push (s[i]);
    //the right parens
    else if (s[i] == '}') {
      if (!stack.empty() && stack.top() == '{')
        stack.pop();
      else
        return false;
    }
    else if (s[i] == ')') {
      if (!stack.empty() && stack.top() == '(')
        stack.pop();
      else
        return false;
    }
    else if (s[i] == ']') {
      if (!stack.empty() && stack.top() == '[')
        stack.pop();
      else
        return false;
    }
  }
  if (!stack.empty() )
    return false;
  return true;
}

int main()
{
  string s = "[])";
  cout << isValid (s) << endl;
}

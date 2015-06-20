#include <string>
#include <stack>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;


int eval (int a, int b, char op)
{
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    default:
      exit (-1);
  }
}


//to be edited
int evalPN (vector<string>& tokens)
{
  //scan from right to left
  stack<int> s;
  for (int i = tokens.size() - 1; i >= 0 ; i--) {
    if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
      //get two operands from the stack
      int a = s.top();
      s.pop();
      int b = s.top();
      s.pop();
      int res = eval (b, a, tokens[i][0]);
      s.push (res);
    }
    else
      s.push (atoi (tokens[i].c_str() ) );
  }
  return s.top();
}

/*
  Evaluate the value of an arithmetic expression in Reverse Polish Notation.
  Valid operators are +, -, *, /. Each operand may be an integer or another expression.
  Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

int evalRPN (vector<string>& tokens)
{
  stack<int> s;
  for (int i = 0; i < tokens.size(); i++) {
    if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
      //get two operands from the stack
      int a = s.top();
      s.pop();
      int b = s.top();
      s.pop();
      int res = eval (b, a, tokens[i][0]);
      s.push (res);
    }
    else
      s.push (atoi (tokens[i].c_str() ) );
  }
  return s.top();
}


int main()
{
  //["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  //["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  /*
  vector<string> tokens;
  tokens.push_back ("4");
  tokens.push_back ("13");
  tokens.push_back ("5");
  tokens.push_back ("/");
  tokens.push_back ("+");
  */
  //− * / 15 − 7 + 1 1 3 + 2 + 1 1
  vector<string> tokens;
  tokens.push_back ("-");
  tokens.push_back ("*");
  tokens.push_back ("/");
  tokens.push_back ("15");
  tokens.push_back ("-");
  tokens.push_back ("7");
  tokens.push_back ("+");
  tokens.push_back ("113");
  tokens.push_back ("+");
  tokens.push_back ("2");
  tokens.push_back ("+");
  tokens.push_back ("11");
  printf ("%d\n", evalPN (tokens) );
}

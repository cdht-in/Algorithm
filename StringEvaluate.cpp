//"22+33/44%34+23-43*234-32+12"

#include <stack>
#include <cstring>
#include <cstdlib>
#include <cstdio>

void oper (char c, std::stack<int>& val, int a, int b)
{
  if (c == '%')
    val.push (a % b);
  else if (c == '*')
    val.push (a * b);
  else if (c == '/')
    val.push (a / b);
  else if (c == '+')
    val.push (a + b);
  else
    val.push (a - b);
}

void EvalEquation (std::stack<int>& val, std::stack<char>& op)
{
  int a = val.top();
  val.pop();
  int b = val.top();
  val.pop();
  char c = op.top();
  op.pop();
  oper (c, val, b, a);
}


int Eval (const char* s)
{
  //define preference for operators
  char preference[256];
  preference[ (int) '+'] = 0;
  preference[ (int) '-'] = 0;
  preference[ (int) '*'] = 1;
  preference[ (int) '/'] = 1;
  preference[ (int) '%'] = 2;
  std::stack<int> val;
  std::stack<char> op;
  char temp[128];
  int j = 0;
  int i = 0;
  for (; s[i] != '\0'; i++) {
    if (s[i] == '+' || s[i] == '/' || s[i] == '%' || s[i] == '*' || s[i] == '-') {
      //push the number onto the stack
      memcpy (temp, s + j, i - j);
      temp[i - j] = '\0';
      val.push (atoi (temp) );
      j = i + 1;
      //any operator that has lower preferene would trigger the evaluation
      while (!op.empty() && preference[ (int) s[i]] <= preference[ (int) op.top()]) {
        EvalEquation (val, op);
      }
      op.push (s[i]);
    }
  }
  //push the last number
  memcpy (temp, s + j, i + 1 - j);
  temp[i + 1 - j] = '\0';
  val.push (atoi (temp) );
  //evalue the rest of expression
  while (!op.empty() ) {
    EvalEquation (val, op);
  }
  return val.top();
}

int main()
{
  char s[] = "22+33/11";
  printf ("result is %d\n", Eval (s) );
}

/*
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#include <iostream>

using namespace std;

int reverse (int x)
{
  int ret = 0;
  int rem = 0;
  bool neg = false;
  if (x < 0) {
    neg = true;
    x = -x;
  }
  while (x) {
    ret *= 10;
    rem = (x % 10);
    ret += rem;
    x = x / 10;
  }
  if (neg)
    return -ret;
  else
    return ret;
}

int main()
{
  cout << reverse (321) << endl;
}

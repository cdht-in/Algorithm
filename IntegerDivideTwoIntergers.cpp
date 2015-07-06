/*
  Divide two integers without using multiplication, division and mod operator.
*/

#include <iostream>

using namespace std;

/* first implementation

//slow version
int divide (int dividend, int divisor)
{
  if (divisor == 0)
    return dividend;
  bool rev = false;
  if ( (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ) {
    if (dividend < 0)
      dividend = -dividend;
    else
      divisor = -divisor;
    rev = true;
  }
  else if (dividend < 0 && divisor < 0) {
    dividend = -dividend;
    divisor = -divisor;
  }
  int ret = 0;
  while (1) {
    dividend -= divisor;
    if (dividend >= 0)
      ret++;
    else {
      if (rev)
        return -ret;
      return ret;
    }
  }
}

int divide1 (int dividend1, int divisor1)
{
  signed long long int dividend = dividend1;
  signed long long int divisor = divisor1;
  if (divisor == 0)
    return dividend;
  bool rev = false;
  if ( (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ) {
    if (dividend < 0)
      dividend = -dividend;
    else
      divisor = -divisor;
    rev = true;
  }
  else if (dividend < 0 && divisor < 0) {
    dividend = -dividend;
    divisor = -divisor;
  }
  int ret = 0;
  while (dividend >= divisor) {
    int i = 0;
    while((divisor << i) <= dividend){
      i++;
    }
    i--;
    ret += (1 << i);
    dividend -= (divisor << i);
  }
  if (rev)
    return -ret;
  return ret;
}

*/

//second implementation

int divide(int dividend, int divisor) {
    signed long long int dividend = dividend1;
    signed long long int divisor = divisor1;
    if (divisor == 0)
      return dividend;
    bool rev = false;
    if ( (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ) {
      if (dividend < 0)
        dividend = -dividend;
      else
        divisor = -divisor;
      rev = true;
    }
    else if (dividend < 0 && divisor < 0) {
      dividend = -dividend;
      divisor = -divisor;
    }
    int ret = 0;
    while (dividend >= divisor) {
      int i = 0;
      while((divisor << i) <= dividend){
        i++;
      }
      i--;
      ret += (1 << i);
      dividend -= (divisor << i);
    }
	
    if (rev)
      return ret = -ret;
	
	//take care of integer overflow
	if(ret > INT_MAX || ret < INT_MIN)
		return INT_MAX;
	
    return ret;
}

int main()
{
  cout << divide1 (10,3) << endl;
}

/*
  Implement pow(x, n).
*/
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

//naive implementation,
double Pow (double x, int n)
{
  if (n == 0)
    return 1.0;
  int f = 0;
  if (n < 0) {
    f = 1;
    n = -n;
  }
  double ret = 1;
  int i;
  for (i = 0; i < n; i++)
    ret *= x;
  return (f) ? 1.0 / ret : ret;
}

/*
int power (int x, unsigned int y)
{
  int temp;
  if ( y == 0)
    return 1;
  temp = power (x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
    }*/


/* 
first implementation

//log(n) approach
double power (double x, int y)
{
  double temp;
  if ( y == 0)
    return 1;
  temp = power (x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else {
    if (y > 0)
      return x * temp * temp;
    else
      //for negative y
      return (temp * temp) / x;
  }
}

*/

//second implementation

double pow(double x, int y) {
    double temp;
	
    if ( y == 0)
      return 1;
	
    temp = pow (x, y / 2);
	
    if (y % 2 == 0)
      return temp * temp;
    else 
	{
      if (y > 0)
        return x * temp * temp;
      else
        //for negative y
        return (temp * temp) / x;
    }	
}










































//third implementation
double powI(double x, int n) 
{
	if(n == 0)
		return 1;
	
	double half = pow(x,n / 2);
	if(n % 2 == 0)
		return half * half;
	else
	{
		if(n > 0)
		 	return x * half * half;
		else
			return half * half / x;
	}
		
}

int main()
{
  printf ("%f\n", powI(3, -2) );
}

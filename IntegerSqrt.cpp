/*
  Implement int sqrt(int x).
  Compute and return the square root of x.
*/

#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

/*
first implementation

//O(log(n)) exponentially cut down, newton method
double Sqrt (double number)
{
  const double ACCURACY = 0.001;
  double lower, upper, guess;
  if (number < 1) {
    lower = number;
    upper = 1;
  }
  else {
    lower = 1;
    upper = number;
  }
  while ( (upper - lower) > ACCURACY) {
    guess = (lower + upper) / 2;
    if (guess * guess > number)
      upper = guess;
    else
      lower = guess;
  }
  return (lower + upper) / 2;
}

float sqrt(int x) {
  float upper,lower,guess;
  if (x < 1) {
    lower = x;
    upper = 1;
  }
  else {
    lower = 1;
    upper = x;
  }
  float precision = 0.01;
  while ((upper - lower) > precision) {
    guess = (lower + upper) / 2;
    if (guess * guess > x)
      upper = guess - 1;
    else
      lower = guess + 1;
  }
  return (upper + lower) / 2;
}

*/

//second implementation
//this would result in TLE in leetcode
int sqrt(int x) {
	if(x == 0 || x == 1)
		return x;
	float l = 1;
	float r = x;
	
	while(l <= r)
	{
		int mid = (l + r) / 2;
		int sqr = mid * mid;
		
		if(sqr == x)
			return mid;
		
		if(sqr > x)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	//shouldn't reach here
	return (l + r) / 2;
}










































//second implementation

int sqrtI(int x) 
{
	int l = 0;
	int r = x;
	float mid = 0;
	while(l <= r)
	{
		mid = l + (r - l) / 2;
		int pow = mid * mid;
		
		if(pow == x)
			return mid;
		
		else if(pow > x)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	
	return (l + r) / 2;
}



int main()
{
	cout << sqrt(2) << endl;
}

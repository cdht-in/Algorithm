/*
	
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return 2147483647

Have you met this question in a real interview? Yes
Example
Given dividend = 100 and divisor = 9, return 11.
	
*/

#include "../commonHeader.h"

int divide(int dividendInput, int divisorInput) 
{
	unsigned int dividend = dividendInput;
	unsigned int divisor = divisorInput;
	
	bool negative = false;
	if(dividendInput < 0 && divisorInput < 0)
	{
		negative = false;
	}
	else if(dividendInput > 0 && divisorInput > 0)
	{
		negative = false;
	}
	else
	{
		if(dividendInput < 0)
			dividend = -dividendInput;
		if(divisorInput < 0)
			divisor = -divisorInput;
		
		negative = true;
	}
		 
	int c = 0;
	while(dividend)
	{
		if(dividend < divisor)
			break;
		
		if(dividend == divisor)
		{
			c++;
			break;
		}
		
		unsigned int newDivisor = divisor;
		unsigned int mulitples = 1;
		while(1)
		{			
			if((newDivisor << 1) >= INT_MAX || (newDivisor << 1) > dividend)
				break;
			
			newDivisor <<= 1;
			mulitples <<= 1;
		}
		
		c += mulitples;
		dividend -= newDivisor;
	}
	
	if(negative)
		return -c;
	return c;
}

int divideI(int dividend, int divisor) {       
    unsigned long dvd = dividend < 0 ? -dividend : dividend;  
    unsigned long dvs = divisor < 0 ? -divisor : divisor;  
    if (dvd < dvs) return 0;  
    int sign = 1;  
    if (dividend < 0) sign *= -1;  
    if (divisor <0) sign *= -1;  
    unsigned long absDivisor = dvs;  
    int step = 0;  
     while (dvs < dvd)  
     {  
          dvs = dvs << 1;  
          step++;  
     }  
     unsigned long result = 0;  
     while (dvd >= absDivisor)  
     {  
          if (dvd >= dvs)  
          {  
               dvd -= dvs;  
               result += (unsigned long) 1 << step;  
          }  
          dvs = dvs >> 1;  
          step--;  
     }  
     return result * sign;  
}  

int main()
{
	cout << divideI(INT_MIN,-1) << endl;
}
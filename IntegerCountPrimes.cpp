/*
  Find all prime numbers under n,then store them in an array
*/

#include <stdio.h>
#include <time.h>
#include <iostream>

using namespace std;

void AllPrimeI (int n)
{
  //there are no primes under 2
  if (n < 2)
    return;
  int count = 1;
  int divisor = 0;
  int divisorsquare = 0;
  int i;
  //skipping all the even numbers
  for (i = 3; i < n; i += 2) 
  {
    divisor = 3;
    for (;; divisor += 2) 
	{
      //each composite number can be factored into two numbers, a * b, one of them has to be smaller than sqrt(n)
      divisorsquare = divisor * divisor;
      if (divisorsquare > i || i % divisor == 0 )
        break;
    }
	
    //found a prime number
    /*
    if (divisorsquare > i) {
      count++;
      printf ("%d ", i);
      }*/
  }
  //printf ("\n");
}

//O(n) time and space
void AllPrime (unsigned int n)
{
  unsigned int i = 3, k = 3;
  unsigned char numbers[n + 1];
  for (; k <= n; k++)
    numbers[k] = (k % 2 == 0) ? 1 : 0;
  //mark off all the composite numbers
  while (i <= n) 
  {
    if (numbers[i] == 0) 
	{
      for (k = 2;  i * k <= n; k++)
        numbers[k * i] = 1;
    }
    i += 2;
  }
  
  /*
  for (i = 3; i <= n; i += 2) {
    if (!numbers[i])
      printf ("%d ", i);
  }
  printf ("\n");
  */
}

//O(nlogn)
int countPrimes(int n) 
{
    bool notPrimeNumber[n + 1];
	notPrimeNumber[0] = true;
	notPrimeNumber[1] = true;
	notPrimeNumber[2] = false;
    for (int i = 3; i < n; i++)
      notPrimeNumber[i] = (i % 2 == 0) ? true : false;
		
    //mark off all the composite notPrimeNumber
    for (int i = 3; i < n; i += 2) 
    {
      	if (notPrimeNumber[i] == false) 
  		{
        	for (int j = 2;  j * i <= n; j++)
          	  notPrimeNumber[j * i] = true;
      	}
    }
	
	//1 and 2
	int c = 0; 
	for(int i = 2; i < n; i++)
	{
		c += ((notPrimeNumber[i] == false)? 1 : 0);
	}
	
	return c;
}

int main()
{
  clock_t b = clock();
  AllPrimeI (1000000);
  clock_t e = clock();
  printf ("%f\n", ((float)e - b) / CLOCKS_PER_SEC);
  b = clock();
  AllPrime (1000000);
  e = clock();
  printf ("%f\n", ((float)e - b) / CLOCKS_PER_SEC);

  cout << countPrimes(3) << endl;
}

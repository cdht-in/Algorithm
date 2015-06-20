/*

  Given a binary representation of an integer say 15 as 1111, find the maximum longest continous sequence of 0s. The twist is it needs to be done in log N. I could think of O(N) solution. but couldn't go for log(N).

  For example. 10000101
  the answer should be 4, because there are 4 continouos zeroes.
*/

#include <cmath>
#include <cstdio>

//Calculates log2 of number.
double Log2( double n )
{
  // log(n)/log(2) is log2.
  return log( n ) / log( 2 );
}

//idea is to decompose the number into addition of power of 2
//log(n)
int LongestZeros(int n){
  int max = 0;
  int lzeros = 0;
  int remainder = 0;
  int szeros = 0;
  while(n > 0){
    lzeros = Log2(n);
    remainder = n - (1 << lzeros);
    if(remainder == 0){
      //n is a power of 2
      if(lzeros > max)
	max = lzeros;
      return max;
    }
    //get the next power of 2
    else{
      szeros = Log2(remainder);
      //minus the leading 1
      if(lzeros - szeros - 1 > max)
	max = lzeros - szeros - 1 ;
    }
    n = remainder;
  }
  return max;
}


int main()
{
  int n = 5;
  printf("%d\n",LongestZeros(n));
  
}

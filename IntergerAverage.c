
#include <stdio.h>

//NOTE might not work in case of integer overflow, to mitigate this, do the division first then, if both a and b are odd, add 1 to the final result (because of flooring two 0.5s)
int Average (int a, int b)
{
  if ( ( (a & 0x01) == 0x01) && (b & 0x01) == 0x01)
    return (a >> 1) + (b >> 1) + 1;
  else
    return (a >> 1) + (b >> 1);
}


int main (void)
{
  int a = (0x01 << 31) - 1;
  int b = 101;
  printf ("%d\n", Average (a, b) );
}


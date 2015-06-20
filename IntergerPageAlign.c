/*
  align the page to give address
*/

#include <stdio.h>

//naive solution:
int getAlignedValue (int pageSize, int valueToAlign)
{
  int index = valueToAlign / pageSize;
  return index * pageSize;
}

//faster solution: only works if the page size is a power of 2
int getAlignedValue_Fast (int pageSize, int valueToAlign)
{
  return valueToAlign & (~ (pageSize - 1) );
}


int main (void)
{
  int pageSize = 7;
  int addr = 24;
  printf ("%d\n", getAlignedValue (pageSize, addr) );
  printf ("%d\n", addr &  ((~pageSize) | (0x01 << 2)) );
  printf ("fast %d\n", addr & (-7) );
}

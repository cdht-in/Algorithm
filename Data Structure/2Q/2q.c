#include <stdio.h>
#include "Hash.h"

//LRU

int main (int argc, char** argv)
{
  int qsize = 4;
  Init (qsize);

  //addr is an array with integers used to simulate the memory references
  int addr[] = {0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 5, 5, 6, 6};
  int size = sizeof (addr) / sizeof (int);
  int i;
  for (i = 0; i < size ; i++) {
    Insert (addr[i]);
  }
  printf ("%.2f\n", (float) hit / size);
}

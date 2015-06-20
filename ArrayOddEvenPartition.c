/* sort the array so that the odd number in front of the even number and their relative order doesn't change in O(n) */

#include <stdio.h>

void Swap (int* a, int* b)
{
  int c = *a;
  *a = *b;
  *b = c;
}

//order changed, non-stable sort
void PartitionI (int* a, int len)
{
  int i;
  int j = len - 1;
  for (i = 0; i < j;) {
    if (a[i] & 0x1 == 0x1)
      i++;
    else {
      Swap (a + i, a + j);
      j--;
    }
  }
}

//not stable either
void PartitionII (int* a, int len)
{
  int i = 0;
  int j = len - 1;
  while (i < j) {
    //NOTE the associtivity of &
    while ( (a[i] & 0x1) == 0x1) {
      i++;
    }
    while ( (a[j] & 0x1) == 0x0) {
      j--;
    }
    if (i < j) {
      Swap (a + i, a + j);
      i++;
      j--;
    }
  }
}


//not stable
void QuickPartition (int* a, int size)
{
  //partition odd and even
  int i = 0;
  //to the left of p less than p, the right >= p
  int p = i;
  while (i < size) {
    if ( (a[i] & 0x1) == 0x1) {
      Swap (a + i, a + p);
      p++;
    }
    i++;
  }
  //Swap (a + size - 1, a + p);
  /*
    for(i = p; i < size; i++){
    Swap (a + i , a + size - 1);
    }*/
  printf ("%d\n", p);
}

int main()
{
  int a[] = {5,4};
  int size = sizeof (a) / sizeof (int);
  QuickPartition (a, size);
  //PartitionII (a, size);
  int i;
  for (i = 0; i < size; i++) {
    printf ("%d ", a[i]);
  }
  printf ("\n");
  return 0;
}

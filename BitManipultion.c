#include <stdio.h>

/* test if the number of 1 in an integer is even or odd
   O(m) where m is the # of set bits
 */
void NumberOfOne (int n)
{
  unsigned int tmp = n;
  int c = 0;
  while (tmp) {
    //clear the least siginificant 1
    tmp &= tmp - 1;
    c++;
  }
  if (c & 0x01 == 0x01)
    printf ("odd\n");
  else
    printf ("even\n");
}

//reverse all bits in 32 bits int
int ReverseInt (int n)
{
  int i = 0, j = 0;
  int len = sizeof (n) * 8;
  for (; i < len / 2; i++) {
    j = len - 1 - i;
    if ( (n & (0x01 << i) ) != ( (n & (0x01 << j) ) >> j) ) {
      //swap those two bits by toggle each one
      n ^= (0x01 << j);
      n ^= (0x01 << i);
    }
  }
  return n;
}

static const unsigned char BitReverseTable256[256] = {
#   define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64
#   define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#   define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )
  R6 (0), R6 (2), R6 (1), R6 (3)
};

void Swap (char* a, char* b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

int main()
{
  unsigned char v = 3;     // input bits to be reversed
  unsigned char r = v; // r will be reversed bits of v; first get LSB of v
  int s = sizeof (v) * 8 - 1; // extra shift needed at end
  while (v) {
    r |= v & 1;
    s--;
    r <<= 1;
    v >>= 1;
  }
  r <<= s; // shift when v's highest bits are zero
  printf ("%d\n", r);
}

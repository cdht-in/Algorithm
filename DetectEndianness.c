/*
  Simple application to detect endianness
*/
#include <stdio.h>

//big endian, the most significant byte on the lower address of memory. little endian, the least significant byte on the lower address of memory

//0 => big endian, 1 => little endian
int Endianness()
{
  unsigned int i = 0x01;
  unsigned char* p = (unsigned char*) &i;
  if (*p == 0x01)
    return 1;
  return 0;
}

int is_big_endian (void)
{
  typedef unsigned int uint32_t;
  union {
    uint32_t i;
    char c[4];
  } bint = {0x01020304};
  return bint.c[0] == 1;
}


int main()
{
  printf ("%d\n", Endianness() );
  printf ("%d\n", is_big_endian() );
}

#include "Util.h"
#include <cstdlib>
#include <cstdio>

static const char alphanum[] =
  "0123456789"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "abcdefghijklmnopqrstuvwxyz";

static const char loweralpha[] = "abcdefghijklmnopqrstuvwxyz";

//problem with this is that it might cause integer overflow
int Util::atoi (const char* s)
{
  if (s[0] == '\0')
    return -1;
  int i = 0;
  bool invert = false;
  if (s[0] == '-') {
    i++;
    invert = true;
  }
  int total = 0;
  for (; s[i] != '\0'; i++) {
    //shift the most significant bit to the left by 1
    total *= 10;
    total += (s[i] - '0');
  }
  total = (invert) ? -total : total;
  return total;
}

char* Util::itoa (int a)
{
  if (a == 0) {
    char* ret = new char[2];
    ret[0] = '0';
    ret[1] = '\0';
    return ret;
  }
  //only support 128 bit integer now
  char* ret = new char[128];
  //i will be the string len
  int i = 0;
  if (a < 0) {
    ret[i++] = '-';
    //invert a
    a = -a;
  }
  //a will become 0
  while (a > 0) {
    //get the last digit
    int mod = a % 10;
    //get the next digit
    a = (a - mod) / 10;
    //need to reverse the string
    ret[i++] = (char) ( (int) '0' + mod);
  }
  //reverse the string
  int x = (ret[0] == '-') ? 1 : 0;
  //NOTE that i is the len, so the i - 1 is the last character
  //last character
  int j = i - 1;
  while (x < j) {
    Swap (ret + x, ret + j);
    x++;
    j--;
  }
  ret[i] = '\0';
  return ret;
}

void Util::Memcpy (void* dest, const void* src, int size)
{
  unsigned char* pdest = (unsigned char*) dest;
  unsigned char* psrc = (unsigned char*) src;
  int loops = (size / sizeof (unsigned int) );
  for (int index = 0; index < loops; ++index) {
    * ( (unsigned int*) pdest) = * ( (unsigned int*) psrc);
    pdest += sizeof (unsigned int);
    psrc += sizeof (unsigned int);
  }
  loops = (size % sizeof (unsigned int) );
  //copy the rest of the bytes
  for (int index = 0; index < loops; ++index) {
    *pdest = *psrc;
    ++pdest;
    ++psrc;
  }
}

//alphanum string
void Util::RandomAlphanumString (char* s, int len)
{
  for (int i = 0; i < len; ++i)
    s[i] = alphanum[rand() % (sizeof (alphanum) - 1)];
  s[len] = '\0';
}


void Util::RandomLowerAlphaString (char* s, int len)
{
  for (int i = 0; i < len; ++i)
    s[i] = loweralpha[rand() % (sizeof (loweralpha) - 1)];
  s[len] = '\0';
}

void Util::PrintStringArray (const char** a, int len)
{
  for (int i = 0; i < len; i++)
    printf ("%s\n", a[i]);
  printf ("\n");
}


int main()
{
  printf ("%d\n", Util::atoi("3") );
}

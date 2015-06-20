#ifndef UTIL_H
#define UTIL_H

/*
  util functions
*/

namespace Util {

  inline void Swap (char* a, char* b)
  {
    char tmp = *a;
    *a = *b;
    *b = tmp;
  }

  //problem with this is that it might cause integer overflow
  int atoi (const char* s);

  char* itoa (int a);

  void Memcpy (void* dest, const void* src, int bytes);

  //int OffsetOf (A* struc, int c);

  //randomly generate alphanum string
  void RandomAlphanumString (char* s, int len);

  //randomly generate lower case string
  void RandomLowerAlphaString (char* s, int len);

  //print an array of string
  void PrintStringArray (const char** a, int len);

};
#endif

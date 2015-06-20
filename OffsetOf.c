/*
  return the offset of a member variable from the base of the struct
*/
#include <stdio.h>

//take a struct and number of the member variable
#define offsetof(st, m) ((size_t)(&((st *)0)->m))

struct S {
  int a;
  int b;
  int c;
};

//return the pointer to the base
struct S* Offset (int* p) {
  struct S* s = (struct S*) 0x00;
  int offset = (int)& (s->b);
  return (struct S*) ( (char*) p - offset);
}

int main()
{
  struct S s;
  s.a = 1;
  s.b = 2;
  s.c = 3;
  printf ("%d\n", offsetof (struct S, b) );
  //struct S* p = Offset (&s.b);
  //printf ("%d %d %d\n", p->a, p->b, p->c);
}

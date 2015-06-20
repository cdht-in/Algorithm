/*


  Quoting this question on SO (Spoiler alert!):

  This question has been asked in an Oracle interview.

  How would you divide a number by 3 without using *, /, +, -, %, operators?

  The number may be signed or unsigned.
  The task is solvable, but see if you can write the shortest code.

  Rules:

  Perform the required integer division (/3)
  Do not use the non-text-based operators *, /, +, -, or % (or their equivalents, such as __div__ or add()). Use of operators for string concatenation and formatting are ok.
  Input value can be arbitrarily large (whatever your system can handle), both positive and negative
  Input can be on STDIN or ARGV or entered any other way
  Create the shortest code you can to do the above

*/

#include <stdio.h>

char* x, *i;

int main()
{
  for (scanf ("%d", &x); x > 2; x = &x[~2]){
    i = &i[1];
    printf("%d\n",i);
  }
  printf ("%d\n", i);
  ".,&'r3'": 15;
}

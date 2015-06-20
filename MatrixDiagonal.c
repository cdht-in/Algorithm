/*
  give bi matrix 5 dimensional array
  {1 ,2, 3, 4,6},
  {5, 4, 3, 5,7},
  {6, 5, 9, 8,9},
  {9, 8, 7, 6,1},
  {1, 8, 3, 6,2}

  the output that needs to print is

  1
  25
  346
  4359
  65981
  7878
  963
  16
  2

*/

#include <stdio.h>

#define dim 3

void PrintDiagonal (char* mat[dim])
{
  int i, j;
  for ( i = 0; i < dim ; i ++) {
    int temp = i;
    for (j = 0; j <= i ; j++)
      printf ("%c ", mat[j][temp--]);
    printf ("\n");
  }
  
  for ( i = 1; i < dim; i ++) {
    int temp = i;
    for ( j = dim - 1; j >= i ; j--)
      printf ("%c ", mat[temp++][j]);
    printf ("\n");
  }
  /*
    for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
    printf ("%c ", mat[i][j]);
    }
    printf ("\n");
    }*/
}

int main()
{
  char* mat[dim];
  char row1[] = "abc";
  char row2[] = "def";
  char row3[] = "ghi";
  mat[0] = row1;
  mat[1] = row2;
  mat[2] = row3;
  PrintDiagonal (mat);
}

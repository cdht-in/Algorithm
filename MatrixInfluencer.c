/*
  Consider an X x Y array of 1's and 0s. The X axis represents "influences" meaning that X influences Y. So, for example, if $array[3,7] is 1 that means that 3 influences 7.

  An "influencer" is someone who influences every other person, but is not influenced by any other member.

  Given such an array, write a function to determine whether or not an "influencer" exists in the array.
*/



#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int dim;

//idea is to find if there is a all 1s row and all 0s column on that element, if X != Y, augment it to be a square matrix
char Influencer (unsigned char* mat[dim])
{
  int i, j;
  for (i = 0; i < dim; i++) {
    int f = 1;
    for (j = 0; j < dim; j++) {
      if (mat[i][j] != 1) {
        f = 0;
        break;
      }
    }
    if (f) {
      //check if the column is all 0s
      int k;
      f = 1;
      for (k = 0; k < dim; k++) {
        if (mat[k][i] != 0 && i != j) {
          f = 0;
          break;
        }
      }
      if (f)
        return i;
    }
  }
  return -1;
}

int main()
{
  unsigned char people[] = "abcde";
  dim = strlen (people);
  unsigned char** matrix = calloc (dim, sizeof (unsigned char*) );
  int i, j;
  for (i = 0; i < dim; i++)
    matrix[i] = calloc (dim, sizeof (unsigned char) );
  for (j = 0; j < dim; j++)
    matrix[2][j] = 1;
  for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      printf ("%d ", matrix[i][j]);
    }
    printf ("\n");
  }
  printf ("%d\n", Influencer (matrix) );
  for (j = 0; j < dim; j++)
    free(matrix[j]);
  free(matrix);
}

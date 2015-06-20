/*
  the question is like this: you are given an n x n board filled with letters. a gaming algorithm wants to find and list all the possible words on this board, where "a word" is defined as a string of at least 3 letters, either horizontally or vertically. what's the most time efficient way to do this?

*/

#include <stdio.h>

#define Col 5

//O(n^3)
void PrintBoard (char board[][Col], int n)
{
  //all words starting at (i,j)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf ("at %d %d\n", i, j);
      //to the left
      if (j - 2 >= 0)
        for (int k = j; k >= 0; k--)
          printf ("%c ", board[i][k]);
      printf ("\n");
      //to the right
      if (j + 2 < n)
        for (int k = j; k < n; k++)
          printf ("%c ", board[i][k]);
      printf ("\n");
      //to the top
      if (i - 2 >= 0)
        for (int k = i; k >= 0; k--)
          printf ("%c ", board[k][j]);
      printf ("\n");
      //top the bottom
      if (i + 2 < n)
        for (int k = i; k < n; k++)
          printf ("%c ", board[k][j]);
      printf ("\n");
    }
    printf ("\n");
  }
}

int main()
{
  char board[Col][Col];
  for (int i = 0; i < Col; i++) {
    for (int j = 0; j < Col; j++)
      board[i][j] = 'a' + j;
  }
  //char (*p) [Col] = board;
  //char** f = (char**)(void**)board;
  //printf ("%d %d %d\n",f,p,p[0]);
  PrintBoard (board, Col);
}


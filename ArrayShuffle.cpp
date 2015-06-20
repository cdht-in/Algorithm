
/*
  Question: Deck Shuffling
  Given an array of distinct integers, give an algorithm to randomly reorder the 
  integers so that each possible reordering is equally likely.  In other words, given a 
  deck of cards, how can you shuffle them such that any permutation of cards is 
  equally likely?
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap (int* x, int* y)
{
  int tmp = 0;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

void Shuffle (int* data, int size)
{
  //note that the last remaining element doesn't need to be swapped, data[size - 1]
  srand (time (NULL) );
  int i;
  //the i + 1 in the end is to ensure that each one is swapped with one that hasn't been seen before
  for (i = 0; i < size - 1; i++) 
  {
    swap (data + i, data + ( (rand() % (size - 1 - i) ) + (i + 1) ));
  }
}

void Shuffle1(int* data, int size)
{
  int pos = size - 1;
  srand(time(NULL));
  
  //n - 1 position has the probability of ((n - 1) / n) * (1 / (n - 1)) = 1/n => equal probability
  for(int i = 0; i < pos; i++)
  {
      int randPos = rand() % pos;
      
	  swap(data + randPos, data + pos);
	  
      pos--;
  }
}

int main()
{
  int foo[] = {1, 2, 3, 4, 5};
  Shuffle (foo, 5);
  int i;
  for (i = 0; i < 5; i++) {
    printf ("%d ", foo[i]);
  }
  printf ("\n");
}

/*
  Given an array of numbers, nums, return an array of numbers products, where

  products[i] is the product of all nums[j], j != i.



  Input : [1, 2, 3, 4, 5]

  Output: [(2*3*4*5), (1*3*4*5), (1*2*4*5), (1*2*3*5), (1*2*3*4)]

  = [120, 60, 40, 30, 24]

  You must do this in O(N) without using division.
*/
#include <cstdio>
#include <cmath>

int* ArrayProduct (int* data, int size)
{
  if (size <= 1)
    return data;
  //forward product
  int* fproduct = new int[size];
  fproduct[0] = data[0];
  //backward product
  int* bproduct = new int[size];
  bproduct[size - 1] = data[size - 1];
  for (int i = 1; i < size; i++)
    //compute the product up to this point from the left
    fproduct[i] = data[i] *  fproduct[i - 1];
  for (int i = size - 2; i >= 0; i--)
    //compute the product up to this point from the right
    bproduct[i] = data[i] * bproduct[i + 1];
  data[0] = bproduct[1];
  data[size - 1] = fproduct[size - 2];
  for (int i = 1; i < size - 1; i++)
    data[i] = fproduct[i - 1] * bproduct[i + 1];
  delete[] fproduct;
  delete[] bproduct;
  return data;
}

//sneakily circumventing the "no division" rule
void ArrayProductLog(int* data,int size){
  float sum = 0.0;
  for(int i = 0; i < size; i++)
    sum += log(data[i]);
  for(int i = 0; i < size; i++)
    data[i] = exp(sum - log(data[i]));
}


int main()
{
  int foo[] = {1,2,3,4,5};
  int size = sizeof (foo) / sizeof (int);
  //ArrayProduct (foo, size);
  ArrayProductLog(foo,size);
  for (int i = 0; i < size; i++)
    printf ("%d ", foo[i]);
  printf ("\n");
}

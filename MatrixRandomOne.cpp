#include <stdio.h>
#include <ctime>
#include <time.h>
#include <stdlib.h>

//randomly fill the all zeros matrix with ones, and each cell has the same probability to be chosen

void SetCell(int** matrix,int n, int pos)
{
  int row = pos / n;
  int col = pos % n;
  matrix[row][col] = 1;
}

void Swap(int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

//gotta be a square matrix
void PrintMatrix(int** matrix, int n)
{
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      {
		  printf("%d ",matrix[i][j]);
      }
    printf("\n");
  }
}

//ArrayShuffle and each index is evenly likely to be picked
void RandomFillOne(int** matrix, int n, int k)
{
  int posLen = n * n;
  int* posArray = new int[posLen];
  for(int i = 0; i < posLen; i++)
    {
      posArray[i] = i;
    }
  srand(time(NULL));
  while(k > 0)
    {
      int pos = rand() % posLen;
      SetCell(matrix, n, posArray[pos]);
      //swap this pos to the end to make sure the uniform probability
	  printf("%d %d\n",pos, posLen - 1);	
      Swap(posArray + pos, posArray + posLen - 1);
      posLen--;
      k--;
    }
  delete[] posArray;
}

int main(){ 
	int n = 3; 
	int** data = new int*[n]; 
	for(int i = 0; i < n; i++) 
	{ 
		data[i] = new int[n];
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			data[i][j] = 0;
		}
	}
	RandomFillOne(data,n,3);
	PrintMatrix(data,n);
}

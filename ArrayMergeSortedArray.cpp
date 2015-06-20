/*
  Given two sorted integer arrays A and B, merge B into A as one sorted array.

  Note:
  You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/

#include <iostream>

using namespace std;

/*
first implementation

void merge (int A[], int m, int B[], int n)
{
  if (m == 0 || n == 0) {
    for (int i = 0; i < n; i++)
      A[i] = B[i];
    return;
  }
  int i = 0;
  // 1
  // 2 3
  while (i < m) {
    if (A[i] <= B[0])
      i++;
    else {
      int tmp = A[i];
      A[i] = B[0];
      B[0] = tmp;
      for (int k = 0; k < n - 1 && B[k] > B[k + 1]; k++) {
        tmp = B[k + 1];
        B[k + 1] = B[k];
        B[k] = tmp;
      }
    }
  }
  //append the remainding Bs
  for (int j = 0; j < n; j++) {
    A[i + j] = B[j];
  }
}
*/

//second implementation

void merge(int A[], int m, int B[], int n) {
	if(n == 0)
	{
		return;
	}
		
	if(m == 0)
	{
		for(int i = 0; i < n; i++)
			A[i] = B[i];
		return;
	}
	
	//from the right to left
	int i = m - 1;
	int j = n - 1;
	
	while(i >= 0 && j >= 0)
	{
		if(A[i] > B[j])
		{
			A[i + j + 1] = A[i];
			i--;
		}
		else
		{
			A[i + j + 1] = B[j];
			j--;
		}
	}
	
	if(j >= 0)
	{
		for(int k = 0; k <= j; k++)
		{
			A[k] = B[k];
		}
	}   
}


int main()
{
  int A[] = {2, 0};
  int B[] = {1};
  int m = 1;
  int n = 1;
  merge (A, m, B, n);
  for (int i = 0; i < m + n; i++)
    cout << A[i] << " ";
  cout << endl;
}

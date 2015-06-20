/*
  Given an unsorted integer array, find the first missing positive integer.

  For example,
  Given [1,2,0] return 3,
  and [3,4,-1,1] return 2.

  Your algorithm should run in O(n) time and uses constant space.
*/

#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <climits>
#include <vector>


using namespace std;

/*
first implmentation


int Partition (int* a, int n)
{
  //first partition the list into positives and negatives
  int i = 0;
  int j = n - 1;
  while (i <= j) {
    if (a[i] <= 0)
      i++;
    else {
      int tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
      j--;
    }
  }
  return i;
}

int firstMissingPositive (int* a, int n)
{
  int i = Partition (a, n);
  //i is the starting point of the position numbers
  //if(a[i] <= 0) ==> there are not positive numbers, then return 1
  int* na = a + i;
  int size = n - i;
  int j;
  for (j = 0; j < size; j++) {
    if (abs (na[j]) - 1 < size && na[abs (na[j]) - 1] > 0)
      na[abs (na[j]) - 1] = -na[abs (na[j]) - 1] ;
  }
  for (j = 0; j < size; j++) {
    if (na[j] > 0)
      return j + 1;
  }
  return size + 1;
}

*/

//second implementation

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/*
寻找数组中第一个未出现的正整数，题目本身比较常见，关键在于题目要求只能使用常数额外空间。

A:
虽然不能再另外开辟非常数级的额外空间，但是可以在输入数组上就地进行swap操作。

思路：交换数组元素，使得数组中第i位存放数值(i+1)。最后遍历数组，寻找第一个不符合此要求的元素，返回其下标。整个过程需要遍历两次数组，复杂度为O(n)。
*/
//O(1) space
int firstMissingPositive(int A[], int n) {
	
	int i = 0;
	while (i < n)
	{
	    if (A[i] != (i+1) && A[i] >= 1 && A[i] <= n && A[A[i]-1] != A[i])
	        swap(A[i], A[A[i]-1]);
	    else
	        i++;
	}
	for (i = 0; i < n; ++i)
	    if (A[i] != (i+1))
	        return i+1;
	
	return n + 1;
}

//with O(n) space, bucket sort
int firstMissingPositiveI(int A[], int n) {
	vector<int> check(n,0);
	
	for(int i = 0; i < n; i++)
	{
		//only care about positive numbers
		if(A[i] <= 0)
			continue;
		//because if A[i] > n there first missing number must exist in [1,n] range
		if(A[i] > n)
			continue;
		
		check[A[i] - 1] = 1;
	}
	
	for(int i = 0; i < n; i++)
	{
		if(check[i] == 0)
			return i + 1;
	}
	//NOTE the largest missing possible integer could only be n + 1 when [1..n] is [1,2,3,4,5,..,n];
	return n + 1;
}

int main()
{
  /*
    Given [1,2,0] return 3,
    and [3,4,-1,1] return 2.
  */
  int a[] = {1};
  int size = sizeof (a) / sizeof (int);
  printf ("%d\n", firstMissingPositiveI (a, size) );
}

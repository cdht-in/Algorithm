/*
  sort Colors AC Rate: 1371/4608 My Submissions
  Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

  Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

  Note:
  You are not suppose to use the library's sort function for this problem.

  click to show follow up.

  Follow up:
  A rather straight forward solution is a two-pass algorithm using counting sort.
  First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

  Could you come up with an one-pass algorithm using only constant space?

*/

#include <cstdio>
#include <iostream>

using namespace std;

/*
first implementation

void Swap (int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}


void Print (int* data, int len)
{
  for (int i = 0; i < len; i++) {
    printf ("%d ", data[i]);
  }
  printf ("\n");
}

//one pass to partition, 0,1 array, pre-condition, only consist of 0 and 1
void TwowayPartition (int* data, int len)
{
  int i = 0;
  int j = len - 1;
  //0 to i is always 0, i to j is unknow, j to len is 1
  //the unknown sections is shrinking
  while (i <= j) {
    //first condition makes sure j to len is 1
    if (data[i] > 0) {
      Swap (data + i, data + j);
      j--;
    }
    //this else make sure the 0 to i sections is 0
    else
      i++;
  }
}

void ThreewayPartition (int* data, int len)
{
  enum Color {red, white, blue};
  //the array is divided into 4 sections, red, white, unknown, and blue
  int l = 0;
  int m = l;
  int h = len - 1;
  //Invariant: a[1..Lo-1]=0 and a[Lo..Mid-1]=1 and a[Hi+1..N]=2; a[Mid..Hi] are unknown.
  while (m <= h) {
    //if it is red, move on
    if (data[m] == red) {
      Swap (data + l, data + m);
      l++;
      m++;
    }
    //if it is white, put it in the white section
    else if (data[m] == white)
      m++;
    //if it is blue, put it in the blue section
    else {
      Swap (data + m, data + h);
      h--;
    }
  }
}

*/

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sortColors(int A[], int n) {
	if(n < 2)
		return;
	int l = 0;
	int m = 0;
	int r = n - 1;
	while(m <= r)
	{
		if(A[m] == 0)
		{
			Swap(A + l, A + m);
			m++;
			l++;
		}
		else if(A[m] == 1)
		{
			m++;
		}
		else
		{
			Swap(A + m, A + r);
			r--;
		}
	}
}





































//third implementation
void sortColorsI(int A[], int n) 
{
	int zero = 0;
	int one = 0;
	int two = n - 1;
	while(one <= two)
	{
		if(A[one] == 0)
		{
			Swap(A + one,A + zero);
			zero++;
			one++;
		}
		else if(A[one] == 1)
		{
			one++;
		}
		else
		{
			Swap(A + one,A + two);
			two--;
		}
	}
}

int main()
{
  int foo[] = {1, 0, 0, 0,1, 1, 1, 1, 0, 2, 1,2,0, 2, 1, 0, 2};
  int len = sizeof (foo) / sizeof (int);
  sortColorsI (foo, len);
  for(int i = 0; i < len; i++)
  {
	  cout << foo[i] << " ";
  }
  cout << endl;
}


/*
  Given an array and a value, remove all instances of that value in place and return the new length.

  The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include <algorithm>

using namespace std;

int Compare (int a, int b)
{
  return (a < b) ? a : b;
}

/*
first implementation

int removeElement (int A[], int n, int elem)
{
  if (n < 1)
    return n;
  sort (A, A + n, myobject);
  int p = n;
  for (int i = 0; i < n; i++) {
    if (A[i] == elem) {
      p = i;
      for (++i; i < n && A[i] == A[i - 1]; i++)
        if (i == n)
          break;
      //there are more elements
      while (i < n) {
        A[p++] = A[i++];
      }
      break;
    }
  }
  return p;
}

*/


//second implementation
int removeElement(int A[], int n, int elem) {
	if(n == 0)
		return n;
	int i = 0;
	int p = 0;
	while(i < n)
	{
		if(A[i] == elem)
		{
			int j = i + 1;
			while(j < n && A[j] == elem)
			{
				j++;
			}
			
			//the rest of the array is all elem
			if(j == n)
				return p;
			
			A[p++] = A[j++];
			i = j;
		}
		else
		{
			A[p++] = A[i++];
		}
	}
	return p;
}


int main()
{
}

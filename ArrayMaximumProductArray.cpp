/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

*/
#include <climits>
#include <iostream>

using namespace std;

typedef signed long long int int64_t;

int64_t Max(int64_t a, int64_t b, int64_t c)
{
	a = (a > b)? a : b;
	a = (a > c)? a : c;
	return a;
}

int64_t Min(int64_t a, int64_t b, int64_t c)
{
	a = (a < b)? a : b;
	a = (a < c)? a : c;
	return a;
}


int maxProduct(int A[], int n) {
	if(n < 1)
		return 0;
	if(n == 1)
		return A[0];

	int64_t localMax = A[0];
	int64_t localMin = A[0];
	int64_t max = A[0];
	
	for(int i = 1; i < n; i++)
	{
		int64_t prevMax = localMax;
		int64_t prevMin = localMin;
		localMax = Max(A[i],A[i] * prevMax, A[i] * prevMin);
		localMin = Min(A[i],A[i] * prevMax, A[i] * prevMin);
		max = (localMax > max)? localMax : max;
	}
	
	return max;
}








































//third implementation with indicating the start and end of the subarray
int maxProductI(int A[], int n) 
{
	if(n < 1)
		return 0;
	if(n == 1)
		return A[0];

	int64_t localMax = A[0];
	int64_t localMin = A[0];
	int64_t max = A[0];
	int end = 0;
	
	for(int i = 1; i < n; i++)
	{
		int64_t prevMax = localMax;
		int64_t prevMin = localMin;
		
		localMax = Max(A[i],A[i] * prevMax, A[i] * prevMin);
		
		localMin = Min(A[i],A[i] * prevMax, A[i] * prevMin);
		
		if(localMax > max)
		{
			max = localMax;
			end = i;
		}
	}
	
	//find the start position of the product
	int64_t tmp = max;
	int start = end;
	for(; start >= 0 && tmp != A[start]; start--)
	{
		tmp /= A[start];
	}
	cout << start << " " << end << endl;
	
	return max;
}

int main(){
	int foo[] = {-2,4,2,3};
	int n = sizeof(foo) / sizeof(int);
	cout << maxProductI(foo,n) << endl;
}
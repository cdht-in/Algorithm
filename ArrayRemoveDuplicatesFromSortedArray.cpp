/*
	
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

*/



int removeDuplicates(int A[], int n) {
    if(n <= 1)
		return n;
	int i = 0;
	int p = 0;
	
	while(i < n)
	{
		while(i + 1 < n && A[i] == A[i + 1])
			i++;
		
		A[p++] = A[i++];
	}
	return p;
}

int main()
{
	
}
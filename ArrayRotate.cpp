

/*
	Rotate an array of n elements to the right by k steps.

	For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

//trivial approach with O(n) space
void rotate(int nums[], int n, int k) {
	if(k % n == 0)
		return;
	k = k % n;
	int* tmp = new int[n];
	for(int i = 0; i < k; i++)
	{
		tmp[i] = nums[n - k + i];
	}
	for(int i = 0; i < n - k; i++)
	{
		tmp[k + i] = nums[i];
	}
	for(int i = 0; i < n; i++)
	{
		nums[i] = tmp[i];
	}
	delete[] tmp;
}


int main(){
	
	
}
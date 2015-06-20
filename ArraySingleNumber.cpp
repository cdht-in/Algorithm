/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
	
*/

int singleNumber(int A[], int n) {
	if(n > 0){
		int result = 0;
		for(int i = 0; i < n; i++)
		{
			result ^= A[i];
		}
		return result;
	}
	return 0;
}

	
int main(){
		
	
	
}
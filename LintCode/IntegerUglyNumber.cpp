/*
	
Ugly number is a number that only have factors 3, 5 and 7.

Design an algorithm to find the Kth ugly number. The first 5 ugly numbers are 3, 5, 7, 9, 15 ...

Have you met this question in a real interview? Yes
Example
If K=4, return 9.

Challenge
O(K log K) or O(K) time.
	
*/

#include "../commonHeader.h"

//O(k)
//http://www.cnblogs.com/EdwardLiu/p/4322664.html
long long kthPrimeNumber(int k) 
{
	long long res[k + 1];
	res[0] = 1;
	int k3 = 0, k5 = 0, k7 = 0;
	for (int i = 1; i <= k; i++) 
	{
		//next number is resulted from the minimal among the three
	    res[i] = std::min(std::min(res[k3] * 3, res[k5] * 5), res[k7] * 7);
		
	    if (res[i] / res[k3] == 3)
			k3++;
	    if (res[i] / res[k5] == 5) 
			k5++;
	    if (res[i] / res[k7] == 7) 
			k7++;
	}
	
	return res[k];
}

int main()
{
	cout << kthPrimeNumber(11) << endl;
}
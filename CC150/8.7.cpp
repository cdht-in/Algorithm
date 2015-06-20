/*
	Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and pennies (1 cent), write code to calculate the number of ways of representing n cents.

*/

#include <iostream>

using namespace std;

//o(n^4)
int sum(int n)
{
	int count = 0;
	for (int i = 0; i <= n / 25; i++)
		for (int j = 0; j <= n / 10; j++)
			for (int k = 0; k <= n / 5; k++)
				for (int l = 0; l <= n; l++)
				{
					int v = i * 25 + j * 10 + k * 5 + l;
					if (v == n)
						count ++;
					else if (v > n)
						break;
				}
				
	return count;
}

//O(n^3)
int sumI(int n)
{
	int count = 0;
	for (int i = 0; i <= n / 25; i++)
	{
		int rem1 = (n - i * 25);
		for (int j = 0; j <= rem1 / 10; j++)
		{
			int rem2 = (rem1 - j * 10);
			for (int k = 0; k <=  rem2 / 5; k++)
			{
				count++;	
			}
		}
	}
				
	return count;
}

//recursion O(n^3)
int make_change(int n, int denom)
{
	
    int next_denom = 0;
	
    switch(denom){
    case 25:
        next_denom = 10;
        break;
    case 10:
        next_denom = 5;
        break;
    case 5:
        next_denom = 1;
        break;
    case 1:
        return 1;
    }
    int ways = 0;
	
    for(int i = 0; i * denom <= n; ++i)
        ways += make_change(n - i * denom, next_denom);
		
    return ways;
}


int main()
{
	int n = 100;
	cout << sum(n) << " " << sumI(n) << " " << make_change(n,25) << endl;
	
	
}
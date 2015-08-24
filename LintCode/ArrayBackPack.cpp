/*
	
Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack?

Have you met this question in a real interview? Yes
Example
If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, we can select [2, 3, 5], so that the max size we can fill this backpack is 10. If the backpack size is 12. we can select [2, 3, 7] so that we can fulfill the backpack.

You function should return the max size we can fill in the given backpack.

Note
You can not divide any item into small pieces.

Challenge
O(n x m) time and O(m) memory.

O(n x m) memory is also acceptable if you do not know how to optimize memory.
	
*/

#include "../commonHeader.h"

//return the max less than val
int binarySearch(int val, vector<int>& A)
{
	int l = 0, r = A.size() - 1;
	int mid = 0;
	while(l <= r)
	{
		mid = l + (r - l) / 2;
		if(A[mid] == val)
			return val;
		else if(A[mid] > val)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	
	return (r > 0)? A[r] : 0;
}

//this would fail on memory list exceed
int backPack(int m, vector<int> A) 
{
	sort(A.begin(),A.end());
	vector<vector<int> > dp(m + 1, vector<int>(A.size(), 0));
	
	for(int i = 1; i <= m; i++)
	{	
		dp[i][0] = (i >= A[0])? A[0] : 0;
	}
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j < A.size(); j++)
		{
			//if taking A[j - 1]	
			int remainder = i - A[j];
			int max1 = (remainder >= 0)? dp[remainder][j - 1] + A[j] : 0;
			//if not taking A[j - 1]
			int max2 = dp[i][j - 1];
			dp[i][j] = std::max(max1,max2);
		}
	}
	
	/*
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j < A.size(); j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	return dp[m][A.size() - 1];
}

//this won't work
int backPackI(int m, vector<int> A) 
{
	sort(A.begin(),A.end());
	vector<vector<int> > dp(m + 1,vector<int>(2,0));
	
	for(int i = 1; i <= m; i++)
	{	
		dp[i][0] = (i >= A[0])? A[0] : 0;
	}
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j < A.size(); j++)
		{
			//if taking A[j - 1]	
			int remainder = i - A[j];
			
			int max1 = 0;
			if(remainder >= 0)
			{
				
				//if(i == 6)
					//cout << dp[remainder][(j - 1) % 2] << " " << A[j] << endl;
				max1 = dp[remainder][(j - 1) % 2] + A[j];
			}
			
			//if not taking A[j - 1]
			int max2 = dp[i][(j - 1) % 2];
			dp[i][j % 2] = std::max(max1,max2);
			
		}
		
		/*
		cout << "on " << i << " column : " << (A.size() - 1) % 2 << endl;
		for(int i = 0; i <= m; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/
	}
		
	
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	return dp[m][(A.size() - 1) % 2];
	
}

int main()
{
	vector<int> A = {2,3,5,7};
	int m = 11;
	cout << backPackI(m,A) << endl;
}
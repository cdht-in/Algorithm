/*
	
Hard Copy Books

24% Accepted
Given an array A of integer with size of n( means n books and number of pages of each book) and k people to copy the book. You must distribute the continuous id books to one people to copy. (You can give book A[1],A[2] to one people, but you cannot give book A[1], A[3] to one people, because book A[1] and A[3] is not continuous.) Each person have can copy one page per minute. Return the number of smallest minutes need to copy all the books.

Have you met this question in a real interview? Yes
Example
Given array A = [3,2,4], k = 2.

Return 5( First person spends 5 minutes to copy book 1 and book 2 and second person spends 4 minutes to copy book 3. )

Challenge
Could you do this in O(n*k) time ?
	
*/

#include <vector>
#include <cassert>
#include <iostream>
#include <numeric>

using namespace std;

//brute force
int copyBooksHelper(vector<int> &pages, vector<int>& fromSum,int start, int k)
{
	if(start >= pages.size())
		return 0;
	
	if(k == 1)
	{
		return fromSum[start];
	}
	
	int min = INT_MAX;
	int sum = 0;
	for(int i = start; i < pages.size(); i++)
	{
		sum += pages[i];
		int remainder = copyBooksHelper(pages,fromSum,i + 1, k - 1);
		
		if(sum >= remainder)
		{
			min = (min < sum)? min : sum;
			break;
		}
		else
		{
			min = (min < remainder)? min : remainder;
		}
	}
	
	return min;
}

int copyBooks(vector<int> &pages, int k) 
{
	assert(k >= 1);
	
	if(pages.size() <= k)
	{
		int max = INT_MIN;
		for(int i = 0; i < pages.size(); i++)
		{
			max = (max > pages[i])? max : pages[i];
		}
		return max;
	}
	
	vector<int> fromSum(pages.size(),0);
	fromSum[pages.size() - 1] = pages[pages.size() - 1];
	for(int i = pages.size() - 2; i >= 0; i--)
	{
		fromSum[i] = pages[i] + fromSum[i + 1];
	}
	
	return copyBooksHelper(pages,fromSum,0,k);
}

//http://sidbai.github.io/2015/07/25/Copy-Books/

int copyBooksI(vector<int> &pages, int k)
{
	int n = pages.size();
	vector<vector<int> > dp(k,vector<int>(n,0));
	for(int i = 0; i < n; i++)
	{
		dp[0][i] = (i >= 1)? dp[0][i - 1] + pages[i] : pages[i];
	}
	for(int i = 1; i < k; i++)
	{
		dp[i][0] = dp[0][0];
	}
	
	for(int i = 1; i < k; i++)
	{
		for(int j = 1; j < n; j++)
		{
			int topLeft = std::max(dp[i - 1][j - 1],pages[j]);
			int top = dp[i - 1][j];
			int left = dp[i][j - 1] + pages[j];
			dp[i][j] = std::min(std::min(topLeft,top),left);
		}
	}
	
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	return dp[k - 1][n - 1];
}

//O(n^2 * K)
int copyBooksII(vector<int> &pages, int k) 
{
	int n = pages.size();
	k = min(n, k); // don't need more than n people
	vector<int> sum_from_start(n, 0);
	partial_sum(pages.begin(), pages.end(), sum_from_start.begin());
	vector<vector<int> > minutes(k + 1, vector<int>(n, INT_MAX));
	for (int i = 1; i <= k; i++) 	
	{
	    for (int j = 0; j < n; j++) 
		{
	        if (i == 1 || j == 0) 
			{
	            minutes[i][j] = sum_from_start[j];
				continue;
			}
			
			//this for loop could be optimized away to be O(1)
	        for (int t = j - 1; t >= 0; t--) 
			{
				//as if the two parts copying take place concurrently
	            int curr = max(minutes[i - 1][t], sum_from_start[j] - sum_from_start[t]);
	            minutes[i][j] = min(curr, minutes[i][j]);
	        }
	    }
	}
	return minutes[k][n - 1];
}

int copyBooks(vector<int> &pages, int k) 
{
    int n = pages.size();
    k = min(n, k);
    vector<int> sum_from_start(n, 0);
    partial_sum(pages.begin(), pages.end(), sum_from_start.begin());
    vector<vector<int> > minutes(k + 1, vector<int>(n, INT_MAX));
    for (int j = 0; j < n; j++) 
	{
        minutes[1][j] = sum_from_start[j];
    }
	
    for (int i = 2; i <= k; i++) 
	{
        minutes[i][0] = sum_from_start[1];
        int left = 0, right = 1;
		//at most O(2n) in the while loop
        while (right < n) 
		{
            int curr = sum_from_start[right] - sum_from_start[left];
            minutes[i][right] = min(max(curr, minutes[i - 1][left]), minutes[i][right]);
            if (left < right && minutes[i - 1][left] < curr)
			{
                left++;
            }
            else 
			{
                right++;
				
                // note: we should calculate the next solution starting from left - 1
                if (left > 0)
				{
                    left--;
                }
            }
        }
    }
	
    return minutes[k][n - 1];
}




int main()
{
	vector<int> A({13,999,1,2});
	int k = 2;
	cout << copyBooks(A,k) << endl;
	cout << copyBooksI(A,k) << endl;
}
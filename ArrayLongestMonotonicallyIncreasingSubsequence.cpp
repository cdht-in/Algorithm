#include <vector>
#include <iostream>

using namespace std;

void PrintSeq(vector<int>& seq,vector<int>& trace, int start)
{
	if(start == -1)
	{
		return;
	}
	
	PrintSeq(seq,trace,trace[start]);
	cout << seq[start] << " ";
}

//DP O(n^2) in time and O(n) in space
int LongestIncreasingSubsequenceDP(vector<int>& seq)
{
	int n = seq.size();
    vector<int> dp(n,1);
	vector<int> trace(n,-1);
	int max = 0;
	
	//i stands for the longest subsequence ends here
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(seq[i] > seq[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				trace[i] = j;
			}
		}
	}

	int endPoint = 0;
    for (int i = 0; i < n; i++ )
   	{	if (max < dp[i])
		{
          	max = dp[i];
			endPoint = i;
	  	}
  	}
	
	//print the longest sequence
	PrintSeq(seq,trace,endPoint);
	cout << endl;
	
	return max;
}

int binarySearch(vector<int>& seq,int size, int target)
{
	int l = 0;
	int r = size - 1;
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(seq[mid] == target)
			return mid;
		else if(seq[mid] < target)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	
	return l;
}

//O(nlogn) in time
int LongestIncreasingSubsequenceI(vector<int>& seq)
{
	int n = seq.size();
	
	vector<int> subseq(n,0);
	vector<int> parent(n,-1);
	
	int back = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(back == 0 || seq[subseq[back - 1]] <= seq[i])
		{
			//record its parent	
			parent[i] = subseq[back - 1];
			subseq[back++] = i;
		}
		else
		{
			int insertP = binarySearch(subseq,back,seq[i]);
			subseq[insertP] = i;
			//record its parent	
			parent[i] = subseq[insertP - 1];
		}
	}
	
	//NOTE here the size of the subseq is the longest increasing sequence but it needs the parent array to reconstruct the actual sequence
	int lastIndex = subseq[back - 1];
	
	while(lastIndex >= 0)
	{
		cout << seq[lastIndex] << " ";
		
		if(lastIndex == 0)
			break;
		
		lastIndex = parent[lastIndex];
		
	}
	cout << endl;
		
	return back;
}

int main()
{
	vector<int> seq = {1,5,2,3,6,0,7,8,9};
	cout << LongestIncreasingSubsequenceI(seq) << endl;
}
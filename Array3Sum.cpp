/*
	Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
	
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num) 
{
    sort(num.begin(),num.end());
    vector<vector<int> > ans;
    if(num.size() < 3)
		 return ans;
	
	for(int i = 0;i < num.size() - 2;i++)
	{
	    //the flow can keep first num without duplicate 
	    if(((i-1)>=0) && num[i]==num[i-1]) continue;

	    int start = i + 1;
	    int end = num.size()-1;
	    int target = -num[i];
	    while(start < end)
	    {
	        if(num[start] + num[end] < target)
	        {
	            start++;
	        }
	        else if(num[start] + num[end] > target)
	        {
	            end--;
	        }
	        else
	        {
	            vector<int> tmp(3,0);
	            tmp[0] = num[i];
	            tmp[1] = num[start];
	            tmp[2] = num[end];
	            ans.push_back(tmp);
	            //if first num is same the second num can't be same 
	            //with last find second num
	            //if the first num and second num is not duplicate the
	            //last num shouldn't check
	            while(start<end && num[start]==tmp[1]) start++;
	            if(start>=end) break;
	        }
	    }
	}
	return ans;   
}



struct Pair{
	int x;
	int y;
	Pair(int x, int y):x(x),y(y){};
};


//second implementation, O(n^2), NOTE this would have duplicates
vector<vector<int> > threeSumI(vector<int> &num) 
{
	vector<vector<int> > result;
	
	sort(num.begin(),num.end());
	
	unordered_map<int,vector<Pair> > pairs;
	//get all pairs
	for(int i = 0; i < num.size(); i++)
	{
		for(int j = i + 1; j < num.size(); j++)
		{
			int sum = num[i] + num[j];
			
			if(pairs.find(sum) == pairs.end())
			{
				pairs[sum] = vector<Pair>();
			}
			
			pairs[sum].push_back(Pair(num[i],num[j]));
		}
	}
	
	for(int i = 0; i < num.size(); i++)
	{
		while(i + 1 < num.size() && num[i] == num[i + 1])
			i++;
		
		int diff = -num[i];
		if(pairs.find(diff) != pairs.end())
		{
			//interate all pairs
			for(int j = 0; j < pairs[diff].size(); j++)
			{
				vector<int> sum;
				sum.push_back(num[i]);
				
				sum.push_back(pairs[diff][j].x);
				sum.push_back(pairs[diff][j].y);
								
				result.push_back(sum);
			}
		}
	}
	
	return result;
}


//another approach, O(n^2)
vector<vector<int> > threeSumII(vector<int> &num) 
{

    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) 
	{

        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) 
		{

            int sum = num[front] + num[back];

            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else
			{
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) 
					front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) 
					back--;
            }

        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }

    return res;

}

int main()
{
	vector<int> foo = {-1,0,1};
	
	vector<vector<int> > bar = threeSumII(foo);
	
	for(int i = 0; i < bar.size(); i++)
	{
		for(int j = 0; j < bar[i].size(); j++)
		{
			cout << bar[i][j] << " ";
		}
		cout << endl;
	}
}
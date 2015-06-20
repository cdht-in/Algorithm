/*
	
	Numbers are randomly generated and passed to a method. Write a program to find and maintain the median value as new values are generated.
	
*/

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Median
{
	
public:
	
	//mantain a sorted array with binary search, this would require n^2 * logn
	//apprach I
	int InsertAndReturnMedian(int n)
	{
		if(nums.size() == 0)
		{
			nums.push_back(n);
			return nums[0];
		}
		
		int p = BinarySearch(n);
		nums.insert(nums.begin() + p,n);
		
		int mid = (nums.size() - 1) / 2;
		if(nums.size() % 2 == 0)
		{	
			return (nums[mid] + nums[mid + 1]) / 2;
		}
		else
		{
			return nums[mid];
		}
	}
	
	//apprach II, maintain a max heap and a min heap, retriving median is O(1), overall its O(nlogn)
	int InsertAndReturnMedianI(int v)
	{
		if(max_heap.empty() && min_heap.empty())
		{
			max_heap.push(v);
		}   
		else if(max_heap.empty() == false && min_heap.empty())
		{
			max_heap.push(v);
		}
		else if(max_heap.empty() && min_heap.empty() == false)
		{
			 min_heap.push(v);
		}   
		else
		{
		    if(v < max_heap.top())
			{
				max_heap.push(v);
			}
		    else
			{
				min_heap.push(v);
			}
		}
		
		//调整，保证两个堆的元素数量差别不大于1
		//不要用max_heap.size()-min_heap.size()>1
		//因为size返回的是unsigned类型，当左边相减得到一个负数时，本来为false
		//但会被转为一个大的正数，结果为true，出问题
		while(max_heap.size() > min_heap.size()+1)
		{
		    int data = max_heap.top();
		    min_heap.push(data);
		    max_heap.pop();
		}
		while(min_heap.size() > max_heap.size() + 1)
		{
		    int data = min_heap.top();
		    max_heap.push(data);
		    min_heap.pop();
		}
		
		if(max_heap.empty() && min_heap.empty())
 		    return (1 << 31); //都为空时，返回int最小值
 		if(max_heap.size() == min_heap.size())
 		    return (max_heap.top() + min_heap.top()) / 2;
 		else if(max_heap.size() > min_heap.size())
 		    return max_heap.top();
 		else
 		    return min_heap.top();
	}
	
	//optimized version based on approach I
	int InsertAndReturnMedianII(int v)
	{
		if(max_heap.empty() || v < max_heap.top())
		{
			max_heap.push(v);
		}
		else
		{
			min_heap.push(v);
		}
		
		//调整，保证两个堆的元素数量差别不大于1
		//不要用max_heap.size()-min_heap.size()>1
		//因为size返回的是unsigned类型，当左边相减得到一个负数时，本来为false
		//但会被转为一个大的正数，结果为true，出问题
		while(max_heap.size() > min_heap.size() + 1)
		{
		    int data = max_heap.top();
		    min_heap.push(data);
		    max_heap.pop();
		}
		
		while(min_heap.size() > max_heap.size() + 1)
		{
		    int data = min_heap.top();
		    max_heap.push(data);
		    min_heap.pop();
		}
		
		
 		if(max_heap.size() == min_heap.size())
 		    return (max_heap.top() + min_heap.top()) / 2;
 		else if(max_heap.size() > min_heap.size())
 		    return max_heap.top();
 		else
 		    return min_heap.top();
	}
	
private:
	
	vector<int> nums;
	
    priority_queue<int,vector<int>,less<int> > max_heap;//左边的数
    priority_queue<int,vector<int>,greater<int> > min_heap;//右边的数
	
	int BinarySearch(int n)
	{
		int l = 0;
		int r = nums.size() - 1;
		
		while(l <= r)
		{
			int mid = l + (r - l) / 2;
			
			if(nums[mid] == n)
			{
				return mid;
			}
			else if(nums[mid] < n)
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
};


int main()
{
	Median median;
	
	int n = 10;
	for(int i = 0; i < n; i++)
	{
		cout << median.InsertAndReturnMedian(i) << endl;	
	}
	
	cout << endl;
	for(int i = 0; i < n; i++)
	{
		cout << median.InsertAndReturnMedianII(i) << endl;	
	}
	
	
	
}
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

//this only work on non-negative numbers for now
void bucketSort(vector<int> &num) {
	
	if(num.size() < 2)
		return;
	
	int max = -1;
	
	int n = num.size();
	
	for(int i = 0; i < n; i++)
	{
		if(num[i] > max)
			max = num[i];
	}
	
	//n buckets
	vector<vector<int> > buckets(n,vector<int>());
	
	//distribute numbers into buckets
	for(int i = 0; i < n; i++)
	{
		int index = num[i] / max * (n - 1) ;
		buckets[index].push_back(num[i]);
	}
	
	
	//sort each buckets
	for(int i = 0; i < n; i++)
	{
		sort(buckets[i].begin(),buckets[i].end());
	}
	
	//put each bucket back to the list
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < buckets[i].size(); j++)
		{
			num[i + j] = buckets[i][j];
		}
	}
}


//this is a variance of counting sort bound by the the MAX
void binsort(std::vector<std::size_t>& A){
	
    std::vector<std::vector<std::size_t>> B(MAX + 1);
    for(std::size_t i = 0; i < SIZE; ++i){
        B[A[i]].push_back(A[i]);
    }
    std::size_t current = 0;
    for(std::size_t i = 0; i < MAX; ++i){
        for(auto item : B[i]){
            A[current++] = item;
        }
    }
}


int main()
{
	
	
}
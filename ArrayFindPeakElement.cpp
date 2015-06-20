/*
	
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

#include <vector>
#include <iostream>

using namespace std;

int findPeakElementHelper(const vector<int>& num, int l, int r){
	if(l > r)
		return -1;
	int mid = (l + r ) / 2;
	if(num[mid] > num[mid - 1] && num[mid] > num[mid + 1])
		return mid;
	int result = findPeakElementHelper(num,l,mid - 1);
	if(result == -1)
		result = findPeakElementHelper(num,mid + 1, r);
	return result;
}

int findPeakElement(const vector<int> &num) {
	if(num.size() <= 1)
		return 0;
	if(num[0] > num[1])
		return 0;
	if(num[num.size() - 1] > num[num.size() - 2])
		return num.size() - 1;
	return findPeakElementHelper(num,1,num.size() - 2);
}

int main(){
	int foo[] = {1,2,1};
	vector<int> bar(foo, foo + sizeof(foo) / sizeof(int));
		
	cout << findPeakElement(bar) << endl;
}
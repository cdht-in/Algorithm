/*

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
	
*/
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int findMinHelper(vector<int>& num, int l, int r){
	if(l > r)
		return INT_MAX;
	int mid = (l + r) / 2;
	if(num[mid] < num[mid - 1] && num[mid] < num[mid + 1])
		return num[mid];
	if(num[mid] > num[mid - 1] && num[mid] > num[mid + 1])
		return (num[mid - 1] < num[mid + 1])? num[mid - 1] : num[mid + 1];
	int result = findMinHelper(num,l, mid - 1);
	if(result == INT_MAX)
		return findMinHelper(num, mid + 1, r);
	return result;
}


int findMin(vector<int> &num) {
	if(num.size() < 1)
		return 0;
	if(num.size() == 1)
		return num[0];
	if(num.size() == 2)
		return (num[0] < num[1])?num[0]:num[1];
	int result = findMinHelper(num,1,num.size() - 2);
	result = (result < num[0])? result : num[0];
	result = (result < num[num.size() - 1])? result : num[num.size() - 1];
	return result;
}

int main(){
	int foo[] = {4,5,1,2,3};
	vector<int> bar(foo, foo + sizeof(foo) / sizeof(int));
	cout << findMin(bar) << endl;
	
}
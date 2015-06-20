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
	
	//find the first distinct element
	int midLeft = mid - 1;
	while(midLeft >= l && num[midLeft] == num[midLeft + 1])
		midLeft--;

	//find the first distinct element	
	int midRight = mid + 1;
	while(midRight <= r && num[midRight] == num[midRight - 1])
		midRight++;
	
	if(num[mid] < num[midLeft] && num[mid] < num[midRight])
		return num[mid];
	
	if(num[mid] > num[midLeft] && num[mid] > num[midRight])
		return (num[midLeft] < num[midRight])? num[midLeft] : num[midRight];
	
	int result = findMinHelper(num,l, midLeft);
	
	if(result == INT_MAX)
		return findMinHelper(num, midRight, r);
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
	int foo[] = {2,2,10,10,1,1,2,2};
	vector<int> bar(foo, foo + sizeof(foo) / sizeof(int));
	cout << findMin(bar) << endl;
	
}
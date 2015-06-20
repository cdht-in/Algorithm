/*

Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string.

Example: find “ball” in [“at”, “”, “”, “”, “ball”, “”, “”, “car”, “”,“”, “dad”, “”, “”] will return 4

Example: find “ballcar” in [“at”, “”, “”, “”, “”, “ball”, “car”, “”, “”, “dad”, “”, “”] will return -1
	
*/

#include <vector>
#include <iostream>

using namespace std;


//O(n) at worst, O(logn) on average
int FindString(vector<string>& vec,string target)
{
	int l = 0;
	int r = vec.size() - 1;
	int mid = 0;
	while(l <= r)
	{
		mid = l + (r - l) / 2;
		int tmp = mid;
		while(tmp < r && vec[tmp] == "")
			tmp++;
		
		//all "" to the right
		if(tmp == r)
		{
			r = mid - 1;
			continue;
		}
		
		if(vec[tmp] == target)
			return tmp;
		else if(vec[tmp] < target)
		{
			l = tmp + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return -1;
}

int main()
{
	vector<string> foo = {"at","","","ball","","car",""};
	string target = "car";
	cout << FindString(foo,target) << endl;
}
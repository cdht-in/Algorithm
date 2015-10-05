/*

	Given a set of n nuts of different sizes and n bolts of different sizes. There is a one-one mapping between nuts and bolts. Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.

	We will give you a compare function to compare nut with bolt.

	Have you met this question in a real interview? Yes
	Example
	Given nuts = ['ab','bc','dd','gg'], bolts = ['AB','GG', 'DD', 'BC'].

	Your code should find the matching bolts and nuts.

	one of the possible return:

	nuts = ['ab','bc','dd','gg'], bolts = ['AB','BC','DD','GG'].

	we will tell you the match compare function. If we give you another compare function.

	the possible return is the following:

	nuts = ['ab','bc','dd','gg'], bolts = ['BC','AA','DD','GG'].

	So you must use the compare function that we give to do the sorting.

	The order of the nuts or bolts does not matter. You just need to find the matching bolt for each nut.
	
*/

#include "../commonHeader.h"

class Comparator 
{
	public:
		int cmp(string a, string b)
		{
			/*
			string lowerA = A;
			std::transform(b.begin(), b.end(), b.begin(), ::tolower);
			*/
			string lowerB = b;
			std::transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
			if (a == lowerB)
			{
				return 0;
			}
			else if(a < lowerB)
			{
				return -1;
			}
			return 1;
		}
};

//brute force O(n^2)
void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) 
{
	for(int i = 0; i < nuts.size(); i++)
	{
		for(int j = 0; j < bolts.size(); j++)
		{
			if(compare.cmp(nuts[i],bolts[j]) == 0)
			{
				string tmp = bolts[j];
				bolts[j] = bolts[i];
				bolts[i] = tmp;
				break;
			}
		}
	}
}

int partition(vector<string>& vec,int start, int end, string& pivot,Comparator& compare)
{
	int l = start, mid = start, r = end;
	int p = start;
	while(mid <= r)
	{
		if(compare.cmp(vec[l],pivot) < 0)
		{			
			l++;
			mid++;
		}
		else if(compare.cmp(vec[l],pivot) == 0)
		{
			p = l;
			l++;
			mid++;
		}
		else
		{
			string tmp = vec[r];
			vec[r] = vec[l];
			vec[l] = tmp;
			r--;
		}
	}
	
	string tmp = vec[p];
	vec[p] = vec[r];
	vec[r] = tmp;
	
	return r;
}

void sortNutsAndBoltsIHelper(vector<string> &nuts, int start, int end,vector<string> &bolts, Comparator& compare)
{
	if(start > end)
	{
		return;
	}
	
	//choose the bolts first element as the pivot and sort each others
	 int p = partition(nuts,start,end,bolts[start],compare);
	
	 partition(bolts,start,end,nuts[p],compare);
	
	 sortNutsAndBoltsIHelper(nuts,start, p - 1, bolts,compare);
	
	 sortNutsAndBoltsIHelper(nuts,p + 1, end, bolts,compare);
}

void sortNutsAndBoltsI(vector<string> &nuts, vector<string> &bolts, Comparator compare)
{
	sortNutsAndBoltsIHelper(nuts,0,nuts.size() - 1, bolts,compare);
}

int main()
{
	vector<string> nuts = {"ab","bc","dd","gg"};
	vector<string> bolts = {"AB","GG","DD","BC"};
	Comparator compare;
	sortNutsAndBoltsI(nuts,bolts,compare);
	for(auto& i : nuts)
	{
		cout << i << " ";
	}
	cout << endl;
	
	for(auto& i : bolts)
	{
		cout << i << " ";
	}
	cout << endl;
	
}
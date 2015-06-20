/*
  The set [1,2,3,…,n] contains a total of n! unique permutations.

  By listing and labeling all of the permutations in order,
  We get the following sequence (ie, for n = 3):

  "123"
  "132"
  "213"
  "231"
  "312"
  "321"
  Given n and k, return the kth permutation sequence.

  Note: Given n will be between 1 and 9 inclusive.
*/
#include <string>
#include <iostream>
#include <vector>


using namespace std;

/*
first implementation

int nFact (int n)
{
  int prev = 1;
  if (n <= 1)
    return prev;
  for (int i = 2; i <= n; i++)
    prev *= i;
  return prev;
}

string getPermutation (int n, int k)
{
  if (n < 1)
    return "";
  else if (n == 1)
    return "1";
  string s = "";
  for (int i = 1; i <= n; i++)
    s += to_string (i);
  int p = 1;
  int index = (k - 1) / nFact(n - p);
  int rem = (k - 1) % nFact(n - p);
  while (1) {
    char c = s[p - 1 + index];
    s.erase (s.begin() + p - 1 + index);
    s.insert (p - 1, 1, c);
    index = rem;
    rem = (k - 1) % nFact(n - p);
    if(rem == 0)
      break;
    p++;
  }
  return s;
}

*/

//second implementation
//this would work but it would exceed the time limit since it is n!
void Swap(string& seq, int i, int j)
{
	int tmp = seq[i];
	seq[i] = seq[j];
	seq[j] = tmp;
}

bool getPermutationHelper(string& seq, int start,int& nth,int k)
{
	if(start >= seq.size())
	{
		nth++;
		if(nth == k)
			return true;
	}
	
	for(int i = start; i < seq.size(); i++)
	{
		Swap(seq,i,start);
		
		if(getPermutationHelper(seq,start + 1,nth,k))
			return true;
		
		Swap(seq,i,start);
	}
	//shouldn't reach here
	return false;
}

string getPermutation(int n, int k) {
	
	string seq = "";
	for(int i = 1; i <= n; i++)
	{
		seq += i;
	}
	int nth = 1;
	if(getPermutationHelper(seq,0,nth,k))
		return seq;
	return "";
}

//math problem
string getPermutation(int n, int k) {
	vector<int> nums(n);  
    int permCount =1;  
    for(int i =0; i< n; i++)  
    {  
         nums[i] = i+1;  
         permCount *= (i+1);        
    }  
    // change K from (1,n) to (0, n-1) to accord to index  
     k--;  
     string targetNum;  
     for(int i =0; i< n; i++)  
     {    
          permCount = permCount/ (n-i);  
          int choosed = k / permCount;  
          targetNum.push_back(nums[choosed] + '0');  
          //restruct nums since one num has been picked  
          for(int j =choosed; j< n-i; j++)  
          {  
               nums[j]=nums[j+1];  
          }  
          k = k%permCount;  
     }  
     return targetNum; 
}


int main()
{
  cout << getPermutation (3, 6) << endl;
}

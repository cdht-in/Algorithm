/*

	Write a method to randomly generate a set of m integers from an array of size n. Each element must have equal probability of being chosen.

*/

#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

void swap (int& x, int& y)
{
  int tmp = 0;
  tmp = x;
  x = y;
  y = tmp;
}

using namespace std;

vector<int> Shuffle(vector<int>& data, int k)
{
	vector<int> result;
	
	int pos = data.size() - 1;
	srand(time(NULL));
	
	//n - 1 position has the probability of ((n - 1) / n) * (1 / (n - 1)) = 1/n => equal probability
	for(int i = 0; i < pos & i < k; i++)
	{
	    int randPos = rand() % pos;
	    
 		swap(data[randPos], data[pos]);
		
		result.push_back(data[pos]);
 		  
	    pos--;
	}
  
  	return result;
}


int main()
{
	vector<int> data = {2,3,1,4,5};
	int k = 2;
	vector<int> result = Shuffle(data,k);
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
}
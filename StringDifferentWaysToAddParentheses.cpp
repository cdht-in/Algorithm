/*
	
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
	
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> diffWaysToCompute(string input) 
{
    vector<int> output;
	if(input.size() == 0)
	{
		return output;
	}
	
	for (int i = 0; i < input.size(); i++) 
	{
	    char c = input[i];
	    if (ispunct(c) == false)
			continue;
	    for (int a : diffWaysToCompute(input.substr(0, i)))
	        for (int b : diffWaysToCompute(input.substr(i + 1)))
	            output.push_back(c == '+' ? a + b : c == '-' ? a - b : a * b);
	}	
	
	return output.size() ? output : vector<int>{stoi(input)};
}

int main()
{
	string s = "1+2*2";
	vector<int> ret = diffWaysToCompute(s);
	for(int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << endl;
	}
}
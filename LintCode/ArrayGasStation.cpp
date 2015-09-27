/*
	
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Have you met this question in a real interview? Yes
Example
Given 4 gas stations with gas[i]=[1,1,3,1], and the cost[i]=[2,2,1,1]. The starting gas station's index is 2.

Note
The solution is guaranteed to be unique.

Challenge
O(n) time and O(1) extra space
	
*/

#include "../commonHeader.h"

//O(n) in time
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
{
	int sum = 0;	
	int index = -1;
	int subSum = 0;
	for(int i = 0; i < gas.size(); i++)
	{
		subSum += gas[i] - cost[i];
		sum += gas[i] - cost[i];
		
		//if subSum < 0 than the circle can't start/end at [index,i];
		if(subSum < 0)
		{
			index = i;
			subSum = 0;
		}
	}
	return (sum < 0)? -1 : index + 1;
}
int main()
{
	
}
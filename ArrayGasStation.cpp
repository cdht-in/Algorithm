/*
  There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

  You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

  Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

  Note:
  The solution is guaranteed to be unique.
*/

#include <vector>
#include <iostream>

using namespace std;

int GasStation (vector<int>& gas, vector<int>& cost)
{
  //outer loop to denote which index it starts on
  for (int i = 0; i < gas.size(); i++) {
    //wrap around
    int j = (i != gas.size() - 1) ? (i + 1) : 0;
    int gasleft =  gas[i] - cost[i];
    if (gasleft < 0)
      continue;
    //inter loop to denote travel in circle
    for (; j != i && j < gas.size(); j++) {
      //fill the gas at station j
      gasleft += (gas[j] - cost[j]);
      //not enough gas to the next gas station
      if (gasleft < 0)
        break;
      //travel in circle
      if (j == gas.size() - 1)
        j == 0;
    }
    //traveled a circle
    if (gasleft >= 0)
      return i;
  }
  return -1;
}

/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

*/

//naive O(n^2)
/*
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	if(gas.size() == 0)
		return -1;
	if(gas.size() == 1 && cost.size() == 1 && cost[0] <= gas[0])
		return 0;
	int remainingGas = 0;
	//starting at index 0
	for(int i = 0; i < gas.size(); i++)
	{
		int end = i;
		for(int j = i + 1, )
		//fill the gas
		remaining += gas[0];
		
	}
}
*/

//second implementation
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	int total = 0;
	int left = 0;
	int start = 0;
	for(int i = 0; i < gas.size(); i++)
	{
		total += gas[i] - cost[i];
		left += gas[i] - cost[i];
		//shrink the region where "start" can't start in [0 , i]
		if(left < 0)
		{
			start = i + 1;
			left = 0;
		}
	}
	//can't make any circle
	if(total < 0)
		return -1;
	return start;
}























//third implementation

int canCompleteCircuitI(vector<int> &gas, vector<int> &cost) {
	int sum = 0;
	int subSum = 0;
	int start = -1;
	for(int i = 0; i < gas.size(); i++)
	{
		subSum += gas[i] - cost[i];
		sum += gas[i] - cost[i];
		
		//if the subsum for [i,j] < 0, it can't start at i + 1 either.
		//it is because if it can start at K  in [i,j], then [k , j] must be positive, then in order for [i ,j] to be negative, [i,k] should be negative, then it would have break at k instead of j
		if(subSum < 0)
		{
			subSum = 0;
			start = i + 1;
		}
	}
	if(sum < 0)
		return -1;
	return start;
}





int main()
{
  vector<int> gas ( {5} );
  vector<int> cost ( {4});
  cout << GasStation (gas, cost) << endl;
}

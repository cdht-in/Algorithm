/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
	
*/

#include <iostream>

using namespace std;

int trailingZeroes(int n) {
    int res=0;
           while(n){
               n/=5;
               res+=n;
           }
           return res;   
}


int main(){
	//452137080
	cout << trailingZeroes(28) << endl;
}
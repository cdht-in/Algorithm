/*

Write a method to generate a random number between 1 and 7, given a method that generates a random number between 1 and 5 (i.e., implement rand7() using rand5()).

*/

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <climits>

using namespace std;

//http://www.hawstein.com/posts/19.10.html
int Gen5()
{
  /* initialize random seed: */
    srand (time(0));

    /* generate secret number between 1 and 5: */
    return rand() % 5 + 1;
}

int Gen7()
{
	int x = INT_MAX;
	//this would work but it would run so many times since 8 - 25 are discarded
	while(x > 7)
	{
		//Ran25 generate 1 - 25
		x = 5 * (Gen5() - 1) + Gen5(); 
	}
	return x;
}


//improved version, narrowed the discarded range
int Gen7I()
{
	int x = INT_MAX;
	//this would work but it would run so many times since 8 - 25 are discarded
	while(x > (7 * (25 / 7)))
	{
		//Ran25 generate 1 - 25
		x = 5 * (Gen5() - 1) + Gen5(); 
	}
	return x % 7 + 1;
}

//
// A > b
/*
int Randb()
{
    int x = ~(1<<31); // max int
    while(x > b*(A/b)) // b*(A/b)表示最接近A且小于A的b的倍数
        x = RandA();
    return x%b + 1;
}
*/


int main()
{
	cout << Gen7I() << endl;
	
}
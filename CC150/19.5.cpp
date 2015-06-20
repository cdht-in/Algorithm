/* 

The Game of Master Mind is played as follows:

The computer has four slots containing balls that are red (R ), yellow (Y), green (G) or blue (B). For example, the computer might have RGGB (e.g., Slot #1 is red, Slots #2 and #3 are green, Slot #4 is blue).

You, the user, are trying to guess the solution. You might, for example, guess YRGB.When you guess the correct color for the correct slot, you get a “hit”. If you guess a color that exists but is in the wrong slot, you get a “pseudo-hit”. For example, the guess YRGB has 2 hits and one pseudo hit.

For each guess, you are told the number of hits and pseudo-hits. Write a method that, given a guess and a solution, returns the number of hits and pseudo hits.

*/
#include <vector>
#include <iostream>

using namespace std;

enum Color
{
	R,
	Y,
	G,
	B
};

void Guess(vector<Color> color, vector<Color> guess)
{
	int n = 26;
	int hash[n];
	for(int i = 0; i < n; i++)
	{
		hash[i] = 0;
	}
	
	for(int i = 0; i < color.size(); i++)
	{
		hash[color[i] - 'a']++;
	}
	
	int hit = 0;
	int pseudoHit = 0;
	for(int i = 0; i < guess.size(); i++)
	{
		if(hash[guess[i] - 'a'] > 0)
		{
			pseudoHit++;
			if(guess[i] == color[i])
				hit++;
		}
	}
	cout << "hit is " << hit << " pseudoHit is " << pseudoHit << endl;
}


int main()
{
	vector<Color> solution = {R,Y,G,B};
	vector<Color> guess = {Y,R,R,R};
	Guess(solution,guess);
}
/*
	
Given a dictionary, find all of the longest words in the dictionary.

Have you met this question in a real interview? Yes
Example
Given

{
  "dog",
  "google",
  "facebook",
  "internationalization",
  "blabla"
}
the longest words are(is) ["internationalization"].

Given

{
  "like",
  "love",
  "hate",
  "yes"
}
the longest words are ["like", "love", "hate"].

Challenge
It's easy to solve it in two passes, can you do it in one pass?
	
*/

#include "commonHeader.h"

vector<string> longestWords(vector<string> &dictionary) 
{
	vector<string> ret;
	for(int i = 0; i < dictionary.size(); i++)
	{
		if(ret.empty())
		{
			ret.push_back(dictionary[i]);
		}
		else
		{
			if(dictionary[i].size() == ret.back().size())
			{
				ret.push_back(dictionary[i]);
			}
			else if(dictionary[i].size() > ret.back().size())
			{
				ret.clear();
				ret.push_back(dictionary[i]);
			}
		}
	}
	return ret;
}

int main()
{
	
}
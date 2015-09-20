/*
	
Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().

Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].

Call next() gets you 1, the first element in the list.

Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.

You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.

Hint:

Think of "looking ahead". You want to cache the next element.
Is one variable sufficient? Why or why not?
Test your design with call order of peek() before next() vs next() before peek().
For a clean implementation, check out Google's guava library source code.
Follow up: How would you extend your design to be generic and work with all types, not just integer?
	
*/

#include "./commonHeader.h"

class Iterator 
{
    struct Data;
	Data* data;
	const vector<int>* p;
		
public:
	Iterator(const vector<int>& num)
	{
		p = &num;
	}
	
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next()
	{
	}
	
	// Returns true if the iteration has more elements.
	bool hasNext() const
	{
	}
};

class PeekingIterator : public Iterator 
{
	bool hasPeeked;
	int peekedElement;
	
public:
	PeekingIterator(const vector<int>& num) : Iterator(num),hasPeeked(false),peekedElement()
	{
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() 
	{
		if(hasPeeked == false)
		{
			peekedElement = Iterator::next();
			hasPeeked = true;
		}
		return peekedElement;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() 
	{
		if(hasPeeked == false)
		{
			return Iterator::next();
		}
		
		int result = peekedElement;
		hasPeeked = false;
		peekedElement = 0;
		return result;
	}

	bool hasNext() const 
	{
		return hasPeeked || Iterator::hasNext();
	}
};

int main()
{
	vector<int> num = {1,2,3};
	PeekingIterator iter(num);
}
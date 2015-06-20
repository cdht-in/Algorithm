#include <vector>
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Array;

template <class T>
class Iterator
{
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual T CurrentItem() = 0;
};

template <class T>
class ArrayIterator : public Iterator<T>
{
public:
	ArrayIterator(const Array<T>* arr):mCurIndex(),mArr(arr)
	{		
	}
	
	virtual void First()
	{
		mCurIndex = 0;
	}
	
	virtual void Next()
	{
		mCurIndex++;
	}
	
	virtual bool IsDone()
	{
		return mCurIndex >= mArr->Count();
	}
	
	virtual T CurrentItem()
	{
		if(IsDone())
		{
			throw string("Iterator out of bound");
		}
		
		return mArr->Get(mCurIndex);
	}
	
private:
	int mCurIndex;
	const Array<T>* mArr;
};

template <class T>
class AbstractArray
{
	
public:
	virtual Iterator<T>* CreateIterator() const = 0;	
};

template <class T>
class Array : public AbstractArray<T>
{
	int mSize;
	int curIndex;
	T* mArray;
	
	
public:
	Array(int c = 100): mSize(c),curIndex(), mArray(new T[mSize])
	{
	}
	
	~Array()
	{
		delete[] mArray;
	}
		
	int Count() const
	{
		return mSize;
	}
	
	void Add(T v)
	{
		if(curIndex >= mSize)
		{
			throw string("Array is full");
		}
		
		mArray[curIndex++] = v;
	}
	
	T& Get(int index) const
	{
		if(index >= mSize)
			throw string("Index out of bound");
		
		return mArray[index];
	}
	
	virtual Iterator<T>* CreateIterator() const
	{
		return new ArrayIterator<T>(this);
	}
};

int main()
{
	int n = 10;
	Array<int> array(5);
	for(int i = 0; i < n; i++)
	{
		try
		{
			array.Add(i);
		}
		catch(string s)
		{
			cout << s << endl;
			break;
		}
	}
	
	Iterator<int>* arrayIter = array.CreateIterator();
	
	for(arrayIter->First() ; arrayIter->IsDone() == false; arrayIter->Next())
	{
		cout << arrayIter->CurrentItem() << endl; 
	}
	
	//delete arrayIter;
	
}
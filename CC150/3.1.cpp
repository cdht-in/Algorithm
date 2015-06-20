/*
	
Describe how you could use a single array to implement three stacks.

*/

#include <iostream>

using namespace std;

struct StackNode{
	int val;
	int prev;
};

//first approach, divide the array into three regions
struct Stack
{
	int p1;
	int p2;
	int p3;
	int* data;
	int size;
	
	Stack(int size)
	{
		data = new int[size * 3];
		this->size = size;
		p1 = 0;
		p2 = size;
		p3 = size * 2;
	}
	
	~Stack()
	{
		delete[] data;
	}
	
	//stack number and value
	void Push(int n, int val){
		Expand();
		if(n == 1)
		{
			data[p1++] = val;
		}
		else if(n == 2)
		{
			data[p2++] = val;
		}
		else if(n == 3)
		{
			data[p3++] = val;
		}		
	}
	
	int Pop(int n){
		int ret = 0;
		if(n == 1)
		{
			if(p1 <= 0)
				return 0;
			p1--;
			ret = data[p1];
		}
		else if(n == 2)
		{
			if(p2 <= size)
				return 0;
			p2--;
			ret = data[p2];
		}
		else if(n == 3)
		{
			if(p3 <= size * 2)
				return 0;
			p3--;
			ret = data[p3];
		}
		return ret;
	}
	
private:
	
	void Expand(){
		if(p1 + (p2 - size)  + (p3 - 2 * size) + 10 >= size * 3)
		{
			int sizeTmp = size * 2;
			int* newData = new int[sizeTmp * 3];
			int p1Tmp = 0;
			int p2Tmp = sizeTmp;
			int p3Tmp = sizeTmp * 2;
			for(int i = 0; i < p1; i++)
			{
				newData[p1Tmp++] = data[i]; 
			}
			p1 = p1Tmp;
			
			for(int i = size; i < p2; i++)
			{
				newData[p2Tmp++] = data[i]; 
			}
			p2 = p2Tmp;
			
			for(int i = 2 * size; i < p3; i++)
			{
				newData[p3Tmp++] = data[i]; 
			}
			p3 = p3Tmp;
				
			size = sizeTmp;

		}
	}
	
};

int main()
{
	Stack st(1);
	st.Push(1,1);
	st.Push(1,2);
	st.Push(1,3);
	st.Push(2,9);
	st.Push(3,10);
	
	st.Pop(1);
	st.Pop(1);
	st.Push(1,4);
	cout << st.Pop(1) << endl;
	cout << st.Pop(1) << endl;
}
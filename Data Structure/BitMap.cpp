#include <iostream>
using namespace std;

class Bitmap
{

public:
	
    Bitmap(int range = sizeof(int)) : binSize((sizeof(int) * 8))
	{
        bins = new int[range / binSize + 1];
    }
	
    ~Bitmap()
	{
        delete[] bins;
    }
	
	//NOTE that 1 << pos % binSize == 1 << (pos & 0x1f)
    bool get(int pos)
	{
		int binIndex = pos / binSize;
		
		int offsetInBin = 1 << (pos & 0x1f);
      
        return (bins[binIndex] & offsetInBin) != 0;
    }
	
    void set(int pos)
	{
		int binIndex = pos / binSize;
		
		int offsetInBin = 1 << (pos & 0x1f);
		
        bins[binIndex] |= offsetInBin;
    }

private:
	
    int *bins;
	int binSize;
};

void print_duplicates(int a[], int n, int bitsize)
{
    Bitmap bm(bitsize);
    for(int i = 0; i < n; ++i)
	{
        if(bm.get(a[i] - 1)) // bitmap starts at 0, number starts at 1
            cout << a[i] << endl;
        else
            bm.set(a[i] - 1);
    }
}
int main(){
    int a[] = 
	{
        1,2,3,4,5,32000,7,8,9,10,11,1,2,13,15,16,32000,11,5,8
    };
	
	int max = 32000;
    print_duplicates(a, sizeof(a) / sizeof(int), max);
    return 0;
}
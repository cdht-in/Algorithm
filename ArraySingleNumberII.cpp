/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
The basic idea is to implement a modulo-3 counter (to count how many times "1" occurs) for each bit position.
Such modulo-3 counter needs two bits (B1,B0) to represent. 
(B1,B0): 
(0, 0) : '1' occurs zero times after last resetting,
(0, 1) : '1' occurs one times after last resetting,
(1, 0) : '1' occurs two times after last resetting,
(1, 1) : '1' occurs three times after last resetting, then we need to reset the counter to (0,0)
So to implement such modulo-3 counters, we need three variables (b0, b1, reset)
The n-th bit of b0 is the B0 bit of the modulo-3 counter for the n-th bit (n=0..31 assuming int is 32 bit)
The n-th bit of b1 is the B1 bit of the modulo-3 counter for the n-th bit (n=0..31 assuming int is 32 bit)
The n-th bit of reset is the reset flag of the modulo-3 counter for the n-th bit (n=0..31 assuming int is 32 bit), 

- b0: can be easily implemented with XOR bit operation,  as b0 = b0^ A[i]
- b1: B1 will only be set to 1, when B0 (of the n-th bit counter) =1 and the n-th bit of A[i] = 1, and stay '1' until it is reseted. So b1 |=  b0 & A[i]; 
- The reset flag is set when (B1, B0) = (1,1). So, reset = b0 & b1;
- The reset operation can be done by b0 = b0 ^ reset and b1 = b1 ^ reset;

After updating the b0, b1, reset with all A[], the b0 will be the final result since if the n-th bit of the to-be-found element is 1, then the times of '1' occurs on the n-th bit is 3*x+1, which is 1 after the modulo 3 opertation.   
*/
class Solution {
public:

    int singleNumber(int A[], int n) {
		
        int b0=0, b1=0, reset=0;
        int i;

        if(n > 0)
        {
			for(i = 0; i<n; i++)
        	{
           	 	b1 |= (b0 & A[i]);
            	b0 = b0 ^ A[i];
           		reset = b1 & b0;
            	b1 = b1 ^ reset;
            	b0 = b0 ^ reset;
        	}
        	return b0;
        }
    }
//------------------------------------------------------------------------------------------------------------
/*
//--  Another version with explicit modulo-3 counters implemented, just for reference-----//
    const int int_bitwidth = 32;
    int singleNumber(int A[], int n) {
        int mod3Counter[int_bitwidth];
        int i,j;
        unsigned int temp = 0;

        if(n>0)
        {
            for(i=0; i<int_bitwidth; i++) mod3Counter[i] = 0;

            for(i=0; i<n; i++)
            {
                temp = (unsigned int) A[i];
                for(j=0; j<int_bitwidth; j++)
                {
                    if(temp & 0x1)
                    {
                        mod3Counter[j] = (mod3Counter[j] + 1) % 3;
                    }
                    temp = temp>>1;
                }

                temp =0;
                for(j=0; j<int_bitwidth; j++)
                {
                    temp = temp << 1;
                    if(mod3Counter[int_bitwidth - 1 -j]) 
                    {
                        temp = temp | 0x1;
                    }
                }
            }
            return (int)temp;

        }
    }
*/


using namespace std;

int singleNumber(int A[], int n) {
	
}

int main(){
	
	
}
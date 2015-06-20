/*

	Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)
	
*/

void swap(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(char* s)
{
	int c = 0;
	for(int i = 0; s[i] != '\0';i++)
	{
		c++;
	}
	
	for(int i = 0; i < c / 2; i++)
	{
		swap(s + i, s + c - i);
	}
}
	

int main()
{
	
	
}
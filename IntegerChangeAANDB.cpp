void ChangeAndB(int a, int b, int x, int y)
{
	while(a != x && b != y)
	{
		if(a > x)
			a--;
		else
			a++;
		
		if(b > y)
			b--;
		else
			b++;
	}
	
	if(a == x)
	{
		while(b > y)
			b--;
		while(b < y)
			b++;
	}
	else
	{
		while(a > x)
			a--;
		while(a < x)
			a++;
	}
}
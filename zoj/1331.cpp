#include <stdio.h>
int main()
{
	int i,a,b,c;
	for(i=2;i<=200;i++)
	{
		for(a=2;a<i;a++)
		{
			for(b=2;b<i;b++)
			{
				for(c=2;c<i;c++)
				{
					if(i*i*i==a*a*a+b*b*b+c*c*c)
					{
						if(a<=b&&b<=c)
						{
							printf("Cube = %d, Triple = (%d,%d,%d)\n",i,a,b,c);
						}
					}
				}
			}
		}
	}
    return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-26 21:36:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1334
////Problem Title: 
////Run result: Accept
////Run time:499MS
////Run memory:1376KB
//////////////////System Comment End//////////////////
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
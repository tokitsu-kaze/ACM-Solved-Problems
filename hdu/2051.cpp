////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-27 00:37:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2051
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	int a,i,s;
	while(~scanf("%d",&a))
	{
		s=1;
		i=0;
		while(s<a)
		{
			s=s*2;
			if(s<=a) i++;
		}
		while(a>1)
		{
			if(a-pow(2,i)>=0)
			{
				printf("1");
				a=a-pow(2,i);
				i--;
			}
			else
			{
				printf("0");
				i--;
			}
		}
		while(i!=0)
		{
			printf("0");
			i--;
		}
		if(a==1&&i==0)
		{
			printf("1\n");
		}
		else if(a==0&&i==0) printf("0\n");
	}
	return 0;
} 
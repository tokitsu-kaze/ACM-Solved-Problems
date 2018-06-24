////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-28 19:35:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2000
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	char a,b,c,d;
	while(~scanf(" %c %c %c",&a,&b,&c))
	{
		while(a>b||b>c||a>c)
		{
			if(a>b)
			{
				d=a;
				a=b;
				b=d;
			}
			if(a>c)
			{
				d=a;
				a=c;
				c=d;
			}
			if(b>c)
			{
				d=b;
				b=c;
				c=d;
			}
		}
		printf("%c %c %c\n",a,b,c);
	}
	return 0;
}
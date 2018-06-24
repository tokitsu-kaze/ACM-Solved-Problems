////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-24 22:53:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2007
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	long int x,y,i,a,b,z;
	while(~scanf("%ld%ld",&x,&y))
	{
		if(x>y)
		{
			z=x;
			x=y;
			y=z;
		}
		a=0;
		b=0;
		for(i=x;i<=y;i++)
		{
			if(i%2==0) a=a+i*i;
			else if(i%2!=0) b=b+i*i*i;
		}
		printf("%ld %ld\n",a,b);
	}
	return 0;
}
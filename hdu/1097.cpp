////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-05 11:05:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1097
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int f(int a,int b)
{
	int c=1;
	a=a%10;
	while(b>0)
	{
		if(b%2!=0)
		{
			c=c*a%10;
		}
		a=a*a%10;
		b=b/2;
	}
	return c;
}
int main()
{
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		printf("%d\n",f(a,b));
	}
	return 0;
}
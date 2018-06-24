////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 10:23:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2035
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a,b,c,i;
	while(~scanf("%d%d",&a,&b))
	{
		if(a==0&&b==0) break;
		c=a;
		for(i=0;i<b-1;i++)
		{
			a=a*c;
			a=a%1000;
		}
		printf("%d\n",a);
	}
	return 0;
}
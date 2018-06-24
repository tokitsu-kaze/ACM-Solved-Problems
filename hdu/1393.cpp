////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-27 21:51:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1393
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a,b,i;
	while(~scanf("%d%d",&a,&b))
	{
		if(a==0&&b==0) break;
		for(i=1;i<=100;i++)
		{
			a=(a+a*b)%60;
			if(a==0) break; 
		}
		if(a==0) printf("%d\n",i);
		else printf("Impossible\n");
	}
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-26 22:31:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1391
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,b;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf("%d%d",&a,&b);
			if(a-b==2||a==b)
			{
				if(a%2==0) printf("%d\n",a+b);
				else printf("%d\n",a+b-1);
			}
			else printf("No Number\n");
		}
	}
    return 0;
}
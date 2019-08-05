////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-26 23:13:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1395
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,b,s,i;
	while(~scanf("%d",&n))
	{
		if(n%2==0||n==1)
		{
			printf("2^? mod %d = 1\n",n);
			continue;
		}
		else
		{
			for(i=1,s=1;;i++)
			{
				s*=2;
				s%=n;
				if(s==1) break;
			}
			printf("2^%d mod %d = 1\n",i,n);
		}
	}
    return 0;
}
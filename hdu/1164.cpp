////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-23 19:05:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1164
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i; 
    while(~scanf("%d",&n))
    {
		for(i=2;;)
		{
			if(n%i==0)
			{
				n/=i;
				printf("%d",i);
				if(n==1) break;
				else printf("*");
			}
			else i++;
		}
		printf("\n");
    }
    return 0;
}
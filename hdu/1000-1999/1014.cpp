////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-12 22:16:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1014
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1404KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define min(a,b)((a)>(b)?(b):(a))
int main()
{
    int a,b,flag,i;
    while(~scanf("%d%d",&a,&b))
    {
		for(i=2,flag=0;i<=min(a,b);i++)
		{
			if(a%i==0&&b%i==0)
			{
				printf("%10d%10d    Bad Choice\n\n",a,b);
				flag=1;
				break;
			}
		}
		if(flag==0) printf("%10d%10d    Good Choice\n\n",a,b);
    }
    return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-26 21:06:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1323
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1396KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	int a,i,sum,flag=0;
    while(~scanf("%d",&a))
    {
		if(a==0)
		{
			puts("END OF OUTPUT");
			break;
		}
		if(flag==0)
		{
			puts("PERFECTION OUTPUT");
			flag=1;
		}
		for(i=2,sum=1;i<=sqrt(a);i++)
		{
			if(a%i==0)
			{
				sum+=i+a/i;
			}
		}
		printf("%5d  ",a);
		if(sum<a) printf("DEFICIENT\n");
		else if(sum==a) printf("PERFECT\n");
		else if(sum>a) printf("ABUNDANT\n");
    }
    return 0;
}
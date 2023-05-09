////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-26 21:26:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1330
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,flag=0,i;
	double sum;
    while(~scanf("%d",&n))
    {
		if(flag==0)
		{
			puts("# Cards  Overhang");
			flag=1;
		}
		for(i=1,sum=0;i<=n;i++)
		{
			sum+=1.0/(2*i);
		}
		printf("%5d%10.3lf\n",n,sum);
    }
    return 0;
}
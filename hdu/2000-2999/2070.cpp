////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 19:10:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2070
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    __int64 n,a[100],i;
    while(scanf("%I64d",&n))
    {
		if(n==-1) break;
		a[0]=0;
		a[1]=1;
		for(i=2;i<=n;i++)
		{
			a[i]=a[i-1]+a[i-2];
		}
		printf("%I64d\n",a[n]);
    }
    return 0;
}
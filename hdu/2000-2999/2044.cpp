////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 10:54:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2044
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,i,a,b;
    __int64 f[52];
    f[0]=1;
    f[1]=1;
    f[2]=2;
    for(i=3;i<=51;i++)
    {
		f[i]=f[i-1]+f[i-2];
	}
    while(~scanf("%d",&n))
    {
		while(n--)
		{
			scanf("%d%d",&a,&b);
			printf("%I64d\n",f[b-a]);
		}
    }
    return 0;
}
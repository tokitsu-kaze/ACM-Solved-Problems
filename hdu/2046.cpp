////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 11:11:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2046
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,i,a;
    __int64 f[52];
    f[1]=1;
    f[2]=2;
    for(i=3;i<=50;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    while(~scanf("%d",&n))
    {
        printf("%I64d\n",f[n]);
    }
    return 0;
}
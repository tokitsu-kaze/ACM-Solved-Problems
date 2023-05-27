////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-18 22:19:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2132
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:2200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
__int64 a[100010];
int main()
{
    __int64 n,i;
    a[1]=1;
    for(i=2;i<=100000;i++)
    {
        if(i%3!=0) a[i]=a[i-1]+i;
        else a[i]=a[i-1]+i*i*i;
    }
    while(~scanf("%I64d",&n))
    {
        if(n<0) break;
        else if(n==0) printf("0\n");
        else printf("%I64d\n",a[n]);
    }
    return 0;
}
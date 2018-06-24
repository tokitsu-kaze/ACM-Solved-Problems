////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-07 00:48:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1420
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
__int64 pow2(__int64 a,__int64 b,__int64 c)
{
    __int64 d;
    d=1;
    c=c*10;
    a=a%c;
    while(b>0)
    {
        if(b%2!=0)
        {
            d=d*a%c;
        }
        a=a*a%c;
        b=b/2;
    }
    return d;
}
int main()
{
    __int64 n,a,b,c;
    while(~scanf("%I64d",&n))
    {
        while(n--)
        {
            scanf("%I64d%I64d%I64d",&a,&b,&c);
            printf("%I64d\n",pow2(a,b,c)%c);
        }
    }
    return 0;
}
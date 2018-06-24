////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 11:06:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    __int64 f;
    while(~scanf("%d",&n))
    {
		if(n==1) f=3;
		else f=pow(-1,n)*2+pow(2,n);
		printf("%I64d\n",f);
    }
    return 0;
}
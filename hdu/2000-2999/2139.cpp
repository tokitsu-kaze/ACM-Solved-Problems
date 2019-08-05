////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 20:22:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2139
////Problem Title: 
////Run result: Accept
////Run time:405MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    __int64 n,i;
    __int64 s[25000];
    s[0]=1;
    for(i=3;i<50002;i=i+2) 
    {
		s[i/2]=s[i/2-1]+i*i;
	}
    while(~scanf("%I64d",&n))
    {
		printf("%I64d\n",s[n/2]);
    }
    return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 22:02:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1977
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    __int64 n,a;
    while(~scanf("%I64d",&n))
    {
		while(n--)
		{
			scanf("%I64d",&a);
			printf("%I64d %I64d\n",a*a*a,(a+1)*(a+1)*(a+1));
		}
    }
    return 0;
}
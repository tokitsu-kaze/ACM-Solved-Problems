////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 15:22:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2057
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    __int64 a,b;
    while(~scanf("%I64X%I64X",&a,&b))
    {
		if(a+b<0) printf("-%I64X\n",-a-b);
		else printf("%I64X\n",a+b);
	}
    return 0;
}
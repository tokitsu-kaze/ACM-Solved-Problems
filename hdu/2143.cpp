////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-15 22:18:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2143
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    __int64 a,b,c;
    while(~scanf("%I64d%I64d%I64d",&a,&b,&c))
    {
        if(a+b==c||a+c==b||b+c==a||a*b==c||a*c==b||b*c==a||a&&(b%a==c||c%a==b)||b&&(a%b==c||c%b==a)||c&&(a%c==b||b%c==a))
		printf("oh,lucky!\n");
        else printf("what a pity!\n");
    }
    return 0;
}
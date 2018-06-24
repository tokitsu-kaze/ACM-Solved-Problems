////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-10 21:28:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2090
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1444KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    double a,b,s;
    char c[1000];
    while(scanf("%s%lf%lf",&c,&a,&b)!=EOF)
    {
		s=s+a*b;
    }
    printf("%.1lf\n",s);
    return 0;
}
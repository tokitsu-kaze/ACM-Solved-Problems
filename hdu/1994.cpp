////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 21:42:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1994
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1444KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n;
    double y,q,e,f,g,a,b;
    while(~scanf("%d",&n))
    {
		while(n--)
		{
			scanf("%lf%lf%lf%lf%lf",&y,&q,&e,&f,&g);
			a=y*(1+e/100*q/365);
			a=a*(1+g/100);
			b=y*(1+f/100*(q+365)/365);
			printf("%.1lf\n%.1lf\n",a,b);
		}
    }
    return 0;
}
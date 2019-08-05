////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-15 22:11:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1408
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1432KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
    int i,t,j;
    double a,b; 
    while(~scanf("%lf%lf",&a,&b))
    {
        t=ceil(a/b);
        for(i=1;;i++)
        {
			a-=i*b;
			if(a>0) t++;
			else break;
		}
		printf("%d\n",t);
    }
    return 0;
}
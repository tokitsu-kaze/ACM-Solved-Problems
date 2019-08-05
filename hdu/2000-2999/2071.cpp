////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 16:47:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2071
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1448KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int t,n,i,j;
    double s,a;
    while(~scanf("%d",&t))
    {
        for(i=0;i<t;i++)
        {
			scanf("%d",&n);
			s=0;
			for(j=0;j<n;j++)
			{
				scanf("%lf",&a);
				if(a>s) s=a;
			}
			printf("%.2lf\n",s);
		}
    }
    return 0;
}
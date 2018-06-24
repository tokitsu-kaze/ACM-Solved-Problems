////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 09:56:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2036
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,x[200],y[200],i;
    double sum;
    while(~scanf("%d",&n))
    {
		if(n==0) break;
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		for(i=1;i<n-1;i++)
		{
			sum+=(x[0]*y[i]+x[i]*y[i+1]+y[0]*x[i+1]-x[0]*y[i+1]-y[0]*x[i]-x[i+1]*y[i]);
		}
		printf("%.1lf\n",sum/2);
    }
    return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-29 22:45:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2039
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1472KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i,j,x[10000];
	double a,b,c;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&a,&b,&c);
			if(a+b>c&&a+c>b&&b+c>a) x[i]=1;
			else x[i]=0;
		}
		for(j=0;j<n;j++)
		{
			if(x[j]==0) printf("NO\n");
			else if(x[j]==1) printf("YES\n");
		}
	}
	return 0;
}
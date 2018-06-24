////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-03 14:34:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2023
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1428KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m,i,j,a[51][6],h,g;
	double x[51],y[6];
	while(~scanf("%d%d",&n,&m))
	{
		h=0;
		g=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			x[i]=0;
			for(j=0;j<m;j++)
			{
				x[i]=x[i]+a[i][j];
			}
		}
		for(j=0;j<m;j++)
		{
			y[j]=0;
			for(i=0;i<n;i++)
			{
				y[j]=y[j]+a[i][j];
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%.2lf",x[i]/m);
			if(i==n-1) printf("\n");
			else printf(" ");
		}
		for(j=0;j<m;j++)
		{
			printf("%.2lf",y[j]/n);
			if(j==m-1) printf("\n");
			else printf(" ");
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]>=y[j]/n) h++;
			}
			if(h==m)
			{
				g++;
			}
			h=0;
		}
		printf("%d\n\n",g);
	}
	return 0;
}
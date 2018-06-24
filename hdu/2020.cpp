////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-01 13:58:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2020
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	int n,a[101],i,j,s;
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(j=0;j<n;j++)
		{
			for(i=0;i<n-1;i++)
			{
				if(fabs(a[i])<fabs(a[i+1]))
				{
					s=a[i];
					a[i]=a[i+1];
					a[i+1]=s;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%d",a[i]);
			if(i!=n-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-28 20:41:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2011
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	int n,a,i,j;
	double s;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			s=0;
			scanf("%d",&a);
			if(a==0)
			{
				printf("0.00\n");
				i--;
			}
			else
			{
				for(j=1;j<=a;j++)
				{
					s=s+(1.0/j)*pow(-1,j-1);
				}
				printf("%.2lf\n",s);
			}
		}
	}
	return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-11 14:26:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2561
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int t,n,i,j,a[11],s;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			s=0;
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			}
			for(i=0;i<n-1;i++)
			{
				for(j=0;j<n-1-j;j++)
				{
					if(a[j]>a[j+1]) swap(&a[j],&a[j+1]);
				}
			}
			
			printf("%d\n",a[1]);;
		}
	}
	return 0;
}
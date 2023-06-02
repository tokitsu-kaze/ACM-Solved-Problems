////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-11 14:15:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2550
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1424KB
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
	int t,n,a[100],b[100],i,j,k;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%d%d",&a[i],&b[i]);
			}
			for(i=0;i<n-1;i++)
			{
				for(j=0;j<n-i-1;j++)
				{
					if(a[j]>a[j+1])
					{
						swap(&a[j],&a[j+1]);
						swap(&b[j],&b[j+1]);
					}
				}
			}
			for(i=0;i<n;i++)
			{
				while(b[i]--)
				{
					printf(">+");
					for(j=a[i]-2;j>0;j--)
					{
						printf("-");
					}
					printf("+>\n");
				}
				printf("\n");
			}
		}
	}
	return 0;
}
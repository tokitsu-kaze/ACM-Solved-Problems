////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-05 15:33:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1040
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,m,i,j,a[1001],h,k,b;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[j]);
			}
			for(h=m;h>0;h--)
			{
				for(k=1;k<h;k++)
				{
					if(a[k]<a[k-1])
					{
						b=a[k];
						a[k]=a[k-1];
						a[k-1]=b;
					}
				}
			}
			for(j=0;j<m;j++)
			{
				printf("%d",a[j]);
				if(j!=m-1) printf(" ");
			}
			if(i!=m-1) printf("\n");
        }
    }
    return 0;
}
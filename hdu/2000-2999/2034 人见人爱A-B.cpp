////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 09:29:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2034
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
    int m,n,a[101],b[101],c[101],i,j,k,flag;
    while(~scanf("%d%d",&n,&m))
    {
		if(n==0&&m==0) break;
		memset(c,0,sizeof(c));
        for(i=0;i<n;i++)
        {
			scanf("%d",&a[i]);
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
		}
		for(i=0,k=0;i<n;i++)
		{
			flag=0;
			for(j=0;j<m;j++)
			{
				if(a[i]==b[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0) c[k++]=a[i];
		}
		if(k==0) printf("NULL\n");
		else
		{
			for(i=0;i<k-1;i++)
			{
				for(j=0;j<k-1-i;j++)
				{
					if(c[j]>c[j+1]) swap(&c[j],&c[j+1]);
				}
			}
			for(i=0;i<k;i++)
			{
				printf("%d ",c[i]);
			}
			printf("\n");
		}
    }
    return 0;
}
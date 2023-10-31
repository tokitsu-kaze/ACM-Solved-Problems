#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
	int c=*(int *)a;
	int d=*(int *)b;
	return c-d;
}
int main()
{
	int n,m,a[1001],b[1001],i,j,flag;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(j=0;j<m;j++)
		{
			scanf("%d",&b[j]);
		}
		if(n>m)
		{
			for(i=0;i<m;i++)
			{
				flag=0;
				for(j=0;j<n;j++)
				{
					if(b[i]==a[j])
					{
						flag=1;
						break;
					}
				}
				if(flag==0) a[n++]=b[i];
			}
			qsort(a,n,sizeof(int),cmp);
			for(i=0;i<n;i++)
			{
				printf("%d",a[i]);
				if(i!=n-1) printf(" ");
				else printf("\n");
			}
		}
		else
		{
			for(i=0;i<n;i++)
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
				if(flag==0) b[m++]=a[i];
			}
			qsort(b,m,sizeof(int),cmp);
			for(i=0;i<m;i++)
			{
				printf("%d",b[i]);
				if(i!=m-1) printf(" ");
				else printf("\n");
			}
		}
	}
	return 0;
}
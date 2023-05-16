////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-07 00:50:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1412
////Problem Title: 
////Run result: Accept
////Run time:1248MS
////Run memory:1568KB
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
    int n,m,i,j,s,f;
    int a[20002],b[20002];
    while(~scanf("%d%d",&n,&m))
    {
		f=0;
		if(n<m)
		{
			swap(&n,&m);
			f=1;
		}
		if(f==1)
		{
			for(i=0;i<m;i++)
			{
				scanf("%d",&b[i]);
			}
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			}
			for(i=0;i<m;i++)
			{
				scanf("%d",&b[i]);
			}
		}
		for(i=0;i<m;i++)
		{
			for(j=n-1,s=0;j>=0;j--)
			{
				if(b[i]==a[j]) break;
				else s++;
			}
			if(s==n)
			{
				a[n]=b[i];
				n++;
			}
		}
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1]) swap(&a[j],&a[j+1]);
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
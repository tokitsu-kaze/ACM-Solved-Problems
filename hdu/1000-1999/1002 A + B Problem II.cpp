////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 13:38:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int n,x,y,i,j,k,d,s;
	char a[1001],b[1001];
	int c[1001];
	while(~scanf("%d",&n))
	{
		s=1;
		while(n--)
		{
			scanf("%s %s",a,b);
			memset(c,0,sizeof(c));
			x=strlen(a);
			y=strlen(b);
			d=0;
			for(i=x-1,j=y-1,k=0;i>=0&&j>=0;i--,j--,k++)
			{
				d=a[i]-48+b[j]-48+d;
				c[k]=d%10;
				d=d/10;
			}
			if(k==x)
			{
				for(;j>=0;j--,k++)
				{
					d=b[j]-48+d;
					c[k]=d%10;
					d=d/10;
				}
			}
			else if(k==y)
			{
				for(;i>=0;i--,k++)
				{
					d=a[i]-48+d;
					c[k]=d%10;
					d=d/10;
				}
			}
			if(d!=0)
			{
				c[k]=d;
				k++;
			}
			printf("Case %d:\n",s);
			s++;
			printf("%s + %s = ",a,b);
			for(k=k-1;k>=0;k--)
			{
				printf("%d",c[k]);
			}
			printf("\n");
			if(n!=0) printf("\n");
		}
	}
	return 0;
}
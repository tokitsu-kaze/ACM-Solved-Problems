////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-03 16:43:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2028
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1436KB
//////////////////System Comment End//////////////////
#include <stdio.h>
unsigned long min(unsigned long a,unsigned long b)
{
	unsigned long min;
	if(a<b) min=a;
	else min=b;
	return(min);
}
int main()
{
	int n,i,x,y;
	unsigned long a[10000],j,s;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%lu",&a[i]);
		}
		s=a[0];
		for(i=1;i<n;i++)
		{
			for(j=min(a[i],s);j>0;j--)
			{
				if(a[i]%j==0&&s%j==0)
				{
					y=j;
					break;
				}
			}
			s=s/y*a[i];
		}
		printf("%lu\n",s);
	}
}
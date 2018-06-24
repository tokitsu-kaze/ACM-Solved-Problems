////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 10:30:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2040
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,b,i,j,s,h;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			s=0;
			h=0;
			for(j=1;j<a;j++)
			{
				if(a%j==0) s=s+j;
			}
			if(s==b) h++;
			s=0;
			for(j=1;j<b;j++)
			{
				if(b%j==0) s=s+j;
			}
			if(s==a) h++;
			if(h==2) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
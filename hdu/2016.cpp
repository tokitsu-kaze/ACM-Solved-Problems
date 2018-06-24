////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-30 21:38:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2016
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a[101],i,j,s,h;
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		j=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<a[j]) j=i;
		}
		s=a[0];
		a[0]=a[j];
		a[j]=s;
		for(h=0;h<n;h++)
		{
			printf("%d",a[h]);
			if(h!=n-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-30 23:26:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2019
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,x,i,j,h,a[101];
	while(~scanf("%d%d",&n,&x))
	{
		j=0;
		h=0;
		if(n==0&&x==0) break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>x&&h==0)
			{
				printf("%d",x);
				h=1;
				j++;
				if(j==n+1) printf("\n");
				else printf(" ");
			}
			printf("%d",a[i]);
			j++;
			if(j==n+1) printf("\n");
			else printf(" ");
		}
		if(h==0) printf("%d\n",x);
	}
	return 0;
}
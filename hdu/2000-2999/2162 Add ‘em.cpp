////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 18:03:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2162
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,s,a,i,j=1;
	while(~scanf("%d",&n))
	{
		if(n<=0) break;
		s=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			s=s+a;
		}
		printf("Sum of #%d is %d\n",j,s);
		j++;
	}
	return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-05 11:35:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1235
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i,s,a[1001],b;
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		s=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%d",&b);
		for(i=0;i<n;i++)
		{
			if(a[i]==b) s++;
		}
		printf("%d\n",s);
	}
	return 0;
}
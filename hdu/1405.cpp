////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 11:16:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1405
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,n,j,count,k=1;
	while(~scanf("%d",&n))
	{
		if(n<0) break;
		if(k>1) printf("\n");
		printf("Case %d.\n",k++);
		for(i=2;i*i<=n;i++)
		{
			count=0;
			while(n%i==0)
			{
				n/=i;
				count++;
			}
			if(count>0) printf("%d %d ",i,count);
		}
		if(n>1) printf("%d 1 ",n);
		printf("\n");
	}
	return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-30 22:59:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2018
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i,a[56],s;
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		else if(n<=4) printf("%d\n",n);
		else
		{
			a[1]=1;
			a[2]=1;
			a[3]=1;
			s=4;
			for(i=4;i<n;i++)
			{
				a[i]=a[i-3]+a[i-1];
				s=s+a[i];
			}
			printf("%d\n",s);
		}
	}
	return 0;
}
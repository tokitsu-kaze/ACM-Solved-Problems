////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-26 21:17:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1326
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a[1001],i,ave,sum,k=1;
    while(~scanf("%d",&n))
    {
		if(n==0) break;
		for(i=0,ave=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			ave+=a[i];
		}
		ave=ave/n;
		for(i=0,sum=0;i<n;i++)
		{
			if(a[i]<ave) sum+=ave-a[i];
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",k++,sum);
    }
    return 0;
}
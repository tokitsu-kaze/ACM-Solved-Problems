////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 12:01:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1563
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1404KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,a[201],i;
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		for(i=1;i<n-1;i++)
		{
			if(a[i]!=a[i-1]&&a[i]!=a[i+1]) break;
		}
		printf("%d\n",a[i]);
	}
	return 0;
}
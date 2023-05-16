////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-23 20:02:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1205
////Problem Title: 
////Run result: Accept
////Run time:608MS
////Run memory:9240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
using namespace std;
__int64 a[1000010];
int main()
{
	__int64 n,d,i,sum;
    while(~scanf("%I64d",&n))
    {
		while(n--)
		{
			scanf("%I64d",&d);
			for(i=0,sum=0;i<d;i++)
			{
				scanf("%I64d",&a[i]);
				sum+=a[i];
			}
			sort(a,a+d);
			sum=sum-a[d-1];
			if(sum+1>=a[d-1]) printf("Yes\n");
			else printf("No\n");
		}
    }
    return 0;
}
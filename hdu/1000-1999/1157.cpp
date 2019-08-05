////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-23 18:39:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1157
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1444KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int t,a[10001],i; 
    while(~scanf("%d",&t))
    {
		for(i=0;i<t;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+t);
		printf("%d\n",a[(1+t)/2-1]);
    }
    return 0;
}
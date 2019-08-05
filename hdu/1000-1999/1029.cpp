////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-20 22:06:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1029
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:2588KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000000];
int main()
{
	int n,i,j;
    while(~scanf("%d",&n))
    {
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		printf("%d\n",a[(n+1)/2]);
    }
    return 0;
}
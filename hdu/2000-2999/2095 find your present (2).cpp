////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 18:53:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2095
////Problem Title: 
////Run result: Accept
////Run time:686MS
////Run memory:1400KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,a,b;
    while(~scanf("%d",&n))
    {
		if(n==0) break;
		b=0;
		while(n--)
		{
			scanf("%d",&a);
			b^=a;
		}
		printf("%d\n",b);
	}
    return 0;
}

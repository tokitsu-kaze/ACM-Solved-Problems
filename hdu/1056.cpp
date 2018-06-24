////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-21 20:53:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1056
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1432KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int t;
    double n,sum;
    while(~scanf("%lf",&n))
    {
		if(n==0) break;
		sum=0;
		t=1;
		while(n>sum)
		{
			t++;
			sum+=1.0/t;
		}
		printf("%d card(s)\n",t-1);
	}
    return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-24 17:25:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2006
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int a,n,i,x;
    while(~scanf("%d",&n))
    {
		x=1;
    	for(i=0;i<n;i++)
    	{
			scanf("%d",&a);
			if(a%2!=0) x=x*a;
		}
		printf("%d\n",x);
	}
    return 0;
}
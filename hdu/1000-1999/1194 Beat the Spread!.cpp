////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-23 19:18:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1194
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,b,c,d; 
    while(~scanf("%d",&n))
    {
		while(n--)
		{
			scanf("%d%d",&a,&b);
			c=(a+b)/2;
			d=c-b;
			if(c+d==a&&c-d==b&&c>0&&d>0) printf("%d %d\n",c,d);
			else printf("impossible\n");
		}
    }
    return 0;
}
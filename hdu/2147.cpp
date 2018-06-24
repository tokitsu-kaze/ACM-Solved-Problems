////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-17 21:55:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2147
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m;
    while(~scanf("%d%d",&n,&m))
    {
		if(n==0&&m==0) break;
		if(n%2!=0&&m%2!=0) printf("What a pity!\n");
		else printf("Wonderful!\n");
    }
    return 0;
}
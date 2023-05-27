////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-17 21:47:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1846
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m,c;
    scanf("%d",&c);
    while(c--)
    {
		scanf("%d%d",&n,&m);
		if(n%(m+1)!=0) printf("first\n");
		else printf("second\n");
	}
    return 0;
}
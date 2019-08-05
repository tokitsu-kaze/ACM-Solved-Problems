////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-26 21:53:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1335
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int b,c;
	char a[10],d[10],*end;
	while(~scanf("%s%d%d",a,&b,&c))
	{
		itoa(strtol(a,&end,b),d,c);
		if(strlen(d)>7) printf("  ERROR\n");
		else printf("%7s\n",strupr(d));
	}
    return 0;
}
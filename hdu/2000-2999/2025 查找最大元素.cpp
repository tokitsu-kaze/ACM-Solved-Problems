////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-03 15:16:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2025
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1396KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int x,i,h;
	char a[101],b[1001],c;
	while(gets(a))
	{
		x=strlen(a);
		c=a[0];
		for(i=0;i<x;i++)
		{
			if(a[i]>c) c=a[i];
		}
		for(i=0;i<x;i++)
		{
			printf("%c",a[i]);
			if(a[i]==c) printf("(max)");
		}
		printf("\n");
	}
	return 0;
}
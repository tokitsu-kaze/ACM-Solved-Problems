////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 17:45:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2113
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int x,l=0,i,s;
	char a[1000];
	while(~scanf("%s",&a))
	{
		if(l==1) printf("\n");
		s=0;
		x=strlen(a);
		for(i=0;i<x;i++)
		{
			if((a[i]-48)%2==0) s=s+a[i]-48;
		}
		printf("%d\n",s);
		l=1;
	}
	return 0;
}
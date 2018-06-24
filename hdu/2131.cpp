////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-05 14:21:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2131
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1428KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	int x,i,s;
	char a,b[201];
	while(~scanf(" %c",&a))
	{
		getchar();
		memset(b,0,sizeof(b));
		s=0;
		scanf("%s",b);
		x=strlen(b);
		for(i=0;i<x;i++)
		{
			if(b[i]==a) s++;
		}
		if(islower(a)) a=toupper(a);
		else a=tolower(a);
		for(i=0;i<x;i++)
		{
			if(b[i]==a) s++;
		}
		printf("%.5lf\n",s*1.0/x);
	}
	return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 13:44:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2734
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1392KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int x,i,s;
	char a[1000];
	while(gets(a))
	{
		if(strcmp(a,"#")==0) break;
		s=0;
		x=strlen(a);
		for(i=0;i<x;i++)
		{
			if(a[i]!=' ')
			{
				s=s+(i+1)*(a[i]-64);
			}
			else if(a[i]==' ')
			{
				s=s;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-02 10:53:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2026
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1392KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int x,i;
	char a[101];
	while(gets(a))
	{
		x=strlen(a);
		for(i=1;i<=x;i++)
		{
			if(a[i]-' '==0)
			{
				a[i+1]=a[i+1]-32;
			}
		}
		a[0]=a[0]-32;
		for(i=0;i<x;i++)
		{
			printf("%c",a[i]);
			if(i==x-1) printf("\n");
		}
	}
	return 0;
}
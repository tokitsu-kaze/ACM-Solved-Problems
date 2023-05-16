////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-24 21:24:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1282
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1444KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int n,i,a,b,count,rev[10001];
	char c[101],d[101];
	while(~scanf("%d",&n))
	{
		count=0;
		rev[0]=n;
		sprintf(c,"%d",n);
		strcpy(d,c);
		strrev(c);
		while(strcmp(c,d)!=0)
		{
			a=atoi(c);
			b=atoi(d);
			n=a+b;
			rev[++count]=n;
			sprintf(c,"%d",n);
			strcpy(d,c);
			strrev(c);
		}
		printf("%d\n",count);
		for(i=0;i<count;i++)
		{
			printf("%d--->",rev[i]);
		}
		printf("%d\n",rev[count]);
	}
	return 0;
}
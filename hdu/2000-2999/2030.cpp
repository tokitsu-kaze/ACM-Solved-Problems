////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-03 17:02:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2030
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,j,x,s;
	char a[10000];
	while(~scanf("%d",&n))
	{
		getchar();
		for(i=0;i<n;i++)
		{
			s=0;
			gets(a);
			x=strlen(a);
			for(j=0;j<x;j++)
			{
				if(a[j]<0) s++;
			}
			printf("%d\n",s/2);
		}
	}
	return 0;
}
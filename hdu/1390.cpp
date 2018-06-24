////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-26 22:23:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1390
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n,i,a,flag;
	char d[101];
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			flag=0;
			scanf("%d",&a);
			itoa(a,d,2);
			for(i=strlen(d)-1;i>=0;i--)
			{
				if(d[i]=='1')
				{
					if(flag==1) printf(" ");
					printf("%d",strlen(d)-1-i);
					flag=1;
				}
			}
			printf("\n");
		}
	}
    return 0;
}
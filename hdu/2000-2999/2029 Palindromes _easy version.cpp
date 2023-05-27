////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-02 11:52:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2029
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,j,x,s;
	char a[101];
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			s=0;
			scanf("%s",a);
			x=strlen(a);
			for(j=0;j<x/2;j++)
			{
				if(a[j]-a[x-j-1]==0)
				{
					s++;
				}
			}
			if(x%2==0)
			{
				if(s==x/2) printf("yes\n");
				else printf("no\n");
			}
			else
			{
				if(s==(x-1)/2) printf("yes\n");
				else printf("no\n");
			}
		}
	}
	return 0;
}
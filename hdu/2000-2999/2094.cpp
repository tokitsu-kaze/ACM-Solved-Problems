////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 19:42:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2094
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1480KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
struct game
{
	char name[100];
}men[1001];
int main()
{
    int n,sum,def,i,j,same;
    while(~scanf("%d",&n))
    {
		if(n==0) break;
		getchar();
		same=0;
		for(i=0;i<2*n;i++)
		{
			scanf("%s",men[i].name);
		}
		for(i=0;i<2*n;i++)
		{
			for(j=i+1;j<2*n;j++)
			{
				if(strcmp(men[i].name,men[j].name)==0)
				{
					same++;
					break;
				}
			}
		}
		sum=2*n-same;
		same=0;
		for(i=1;i<2*n;i+=2)
		{
			for(j=i+2;j<2*n;j+=2)
			{
				if(strcmp(men[i].name,men[j].name)==0)
				{
					same++;
					break;
				}
			}
		}
		def=n-same;
		if(sum-def==1) printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}

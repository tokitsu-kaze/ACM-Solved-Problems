////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 22:10:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1976
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,a[7],i;
    while(~scanf("%d",&n))
    {
		while(n--)
		{
			for(i=0;i<6;i++)
			{
				scanf("%d",&a[i]);
			}
			if(a[0]>a[3]) printf("First\n");
			else if(a[0]<a[3]) printf("Second\n");
			else
			{
				if(a[1]>a[4]) printf("First\n");
				else if(a[1]<a[4]) printf("Second\n");
				else
				{
					if(a[2]>a[5]) printf("First\n");
					else if(a[2]<a[5]) printf("Second\n");
					else printf("Same\n");
				}
			}
		}
    }
    return 0;
}
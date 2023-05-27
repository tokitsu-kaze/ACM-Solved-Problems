////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 11:55:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1562
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,b,c,i;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf("%d%d%d",&a,&b,&c);
			for(i=1000;i<10000;i++)
			{
				if(i%a==0&&(i+1)%b==0&&(i+2)%c==0) break;
			}
			if(i==10000) printf("Impossible\n");
			else printf("%d\n",i);
		}
	}
	return 0;
}
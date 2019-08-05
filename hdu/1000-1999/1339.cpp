////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-26 22:07:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1339
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,o,p;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf("%d",&a);
			p=0;
			while(1)
			{
				if(a%2==0)
				{
					a/=2;
					p++;
				}
				else break;
			}
			printf("%d %d\n",a,p);
		}
	}
    return 0;
}
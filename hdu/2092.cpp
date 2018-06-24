////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 19:37:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2092
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,i,s;
    while(scanf("%d%d",&a,&b))
    {
		s=0;
		if(a==0&&b==0) break;
		for(i=-abs(b);i<=abs(b);i++)
		{
			if(i==0) i++;
			if(b%i==0)
			{
				if(b/i+i==a)
				{
					printf("Yes\n");
					s++;
					break;
				}
			}
		}
		if(s==0) printf("No\n");
    }
    return 0;
}
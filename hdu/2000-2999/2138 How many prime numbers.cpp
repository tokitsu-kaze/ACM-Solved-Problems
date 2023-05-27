////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 20:34:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2138
////Problem Title: 
////Run result: Accept
////Run time:811MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
    int n,i,a,s,k;
    while(~scanf("%d",&n))
    {
		s=0;
		k=0;
		while(n--)
		{
			scanf("%d",&a);
			if(a==2||a==3) s++;
			else
			{
				for(i=2;i<=sqrt(a);i++)
				{
					if(a%i==0) break;
				}
				if(i>sqrt(a)) s++;
			}
		}
		printf("%d\n",s);
    }
    return 0;
}
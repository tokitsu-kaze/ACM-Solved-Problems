////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 16:41:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2042
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,a,i,j,s;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
			s=3;
			scanf("%d",&a);
			for(j=0;j<a;j++)
			{
				s=(s-1)*2;
			}
			printf("%d\n",s);
		}
    }
    return 0;
}
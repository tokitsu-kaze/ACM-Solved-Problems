////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 21:16:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2123
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,i,j,a,k,s;
    while(~scanf("%d",&n))
    {
		while(n--)
		{
			scanf("%d",&a);
			for(i=0;i<a;i++)
			{
				k=0;
				for(j=0,k=k+i+1;j<a;j++,k=k+i+1)
				{
					printf("%d",k);
					if(j!=a-1) printf(" ");
					else if(j==a-1) printf("\n");
				}
			}
		}
    }
    return 0;
}
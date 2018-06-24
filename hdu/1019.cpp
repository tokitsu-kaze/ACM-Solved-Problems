////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-18 22:45:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1019
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
} 
int main()
{
    int n,m,a,sum;
    while(~scanf("%d",&n))
    {
        while(n--)
        {
			sum=1;
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&a);
				sum=sum/gcd(sum,a)*a;
			}
			printf("%d\n",sum);
		}
    }
    return 0;
}
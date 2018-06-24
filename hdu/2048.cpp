////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 11:27:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2048
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
__int64 mul(__int64 n)
{
	int i;
	__int64 sum=1;
	for(i=2;i<=n;i++)
	{
		sum*=i;
	}
	return sum;
}
int main()
{
    int n,i,a;
    __int64 f[42];
    f[1]=0;
    f[2]=1;
    for(i=3;i<=40;i++)
    {
        f[i]=(f[i-1]+f[i-2])*(i-1);
    }
    while(~scanf("%d",&n))
    {
		while(n--)
		{
			scanf("%d",&a);
        	printf("%.2lf%%\n",1.0*f[a]/mul(a)*100);
		}
    }
    return 0;
}
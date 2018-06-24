////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 13:11:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2049
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
__int64 cn(__int64 a,__int64 b)
{
	int i,j;
	__int64 sum1=1,sum2=1;
	for(i=a,j=b;i>0,j>0;i--,j--)
	{
		sum1*=i;
		sum2*=j;
	}
	return sum1/sum2;
}
int main()
{
    int n,i,a,b;
    __int64 f[22];
    f[1]=0;
    f[2]=1;
    for(i=3;i<=20;i++)
    {
        f[i]=(f[i-1]+f[i-2])*(i-1);
    }
    while(~scanf("%d",&n))
    {
		while(n--)
		{
			scanf("%d%d",&a,&b);
        	printf("%I64d\n",f[b]*cn(a,a-b));
		}
    }
    return 0;
}
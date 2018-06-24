////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-15 22:29:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1465
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,i;
    __int64 f[100];
    f[1]=0;
    f[2]=1;
    for(i=3;i<100;i++)
    {
		f[i]=(i-1)*(f[i-2]+f[i-1]);
	}
    while(~scanf("%d",&n))
    {
        printf("%I64d\n",f[n]);
    }
    return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-01 16:26:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1094
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,i,s,x;
    while(~scanf("%d",&n))
    {
        s=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            s=s+x;
        }
        printf("%d\n",s);
    }
    return 0;
}
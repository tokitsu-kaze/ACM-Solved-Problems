////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-05 15:12:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2524
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,a,b,i,s;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
			s=0;
            scanf("%d%d",&a,&b);
            s=(1+a)*a/2*(1+b)*b/2;
            printf("%d\n",s);
        }
    }
    return 0;
}
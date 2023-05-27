////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-17 22:35:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1527
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>
#define min(a,b) ((a)>(b)?(b):(a))
int main()  
{  
    int n,m;  
    while(~scanf("%d%d",&n,&m))  
    {
        if(int(abs(n-m)*(sqrt(5.0)+1))/2==min(n,m)) printf("0\n");
        else printf("1\n");
    }  
    return 0;
} 
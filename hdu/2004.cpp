////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-24 16:35:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int t;
    while(~scanf("%d",&t))
    {
        if(t>=0&&t<=59) printf("E\n");
        else if(t>=60&&t<=69) printf("D\n");
        else if(t>=70&&t<=79) printf("C\n");
        else if(t>=80&&t<=89) printf("B\n");
        else if(t>=90&&t<=100) printf("A\n");
        else if(t<0||t>100) printf("Score is error!\n");
    }
    return 0;
}
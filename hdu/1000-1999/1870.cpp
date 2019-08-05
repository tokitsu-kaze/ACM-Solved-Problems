////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-17 00:13:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1870
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    int i,s,x;
    char a[1001];
    while(~scanf("%s",a))
    {
        s=0;
        x=strlen(a);
        for(i=0;i<x;i++)
        {
            if(a[i]=='B') break;
            else if(a[i]==')') s--;
            else if(a[i]=='(') s++;
        }
        printf("%d\n",s);
    }
    return 0;
}
////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-12 21:56:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1013
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    int x,i,s;
    char a[10001];
    while(~scanf("%s",a))
    {
		if(a[0]-'0'==0) break;
		s=0;
		x=strlen(a);
		for(i=0;i<x;i++)
		{
			s+=a[i]-'0';
		}
		if(s%9==0) printf("9\n");
		else printf("%d\n",s%9);
    }
    return 0;
}
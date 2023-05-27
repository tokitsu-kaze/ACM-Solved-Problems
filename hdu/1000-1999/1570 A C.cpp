////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 12:28:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1570
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1560KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
using namespace std;
int fact(int n)
{
	int s=1;
	if(n==1||n==0) return s;
	else
	{
		s*=n;
		return s*fact(n-1);
	}
}
int main()
{
	int n,i,a,b;
	char c;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf(" %c%d%d",&c,&a,&b);
			if(c=='A') printf("%d\n",fact(a)/fact(a-b));
			else printf("%d\n",fact(a)/(fact(b)*fact(a-b)));
		}
	}
	return 0;
}
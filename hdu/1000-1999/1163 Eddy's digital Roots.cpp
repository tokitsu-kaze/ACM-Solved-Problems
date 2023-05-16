////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-23 19:00:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1163
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i,a; 
    while(~scanf("%d",&n))
    {
		if(n==0) break;
		a=1;
		for(i=0;i<n;i++)
		{
			a=a*n%9;
		}
		if(a!=0) printf("%d\n",a);
		else printf("9\n");
    }
    return 0;
}
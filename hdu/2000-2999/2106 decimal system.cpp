////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-10 16:05:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2106
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>
int exchange(int a,int b)
{
	int x,i,s=0,k;
	char c[100];
	sprintf(c,"%d",a);
	x=strlen(c);
	for(i=x-1,k=0;i>=0;i--,k++)
	{
		s=s+(c[i]-48)*pow(b,k);
	}
	return s;
}
int main()
{
    int n,a,b,i,s;
    while(~scanf("%d",&n))
    {
		s=0;
		for(i=0;i<n;i++)
		{
			scanf("%d(%d)",&a,&b);
			s=s+exchange(a,b);
		}
		printf("%d\n",s);
    }
    return 0;
}
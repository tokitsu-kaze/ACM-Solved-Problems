////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-05 11:29:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1229
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a,b,k,s,i;
	while(~scanf("%d%d%d",&a,&b,&k))
	{
		if(a==0&&b==0) break;
		s=1;
		for(i=0;i<k;i++)
		{
			s=s*10;
		}
		if(a%s==b%s) printf("-1\n");
		else printf("%d\n",a+b);
	}
	return 0;
}
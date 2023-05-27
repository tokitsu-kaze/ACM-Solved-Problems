////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 22:52:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1555
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int m,k,d,a;
    while(~scanf("%d%d",&m,&k))
    {
		if(m==0&&k==0) break;
		for(d=1;;d++)
		{
			m--;
			if(d%k==0) m++;
			if(m==0) break;
		}
		printf("%d\n",d);
	}
	return 0;
}
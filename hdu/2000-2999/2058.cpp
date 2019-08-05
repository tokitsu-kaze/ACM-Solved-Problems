////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 16:01:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2058
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
    int n,m,len,lena1;
    while(~scanf("%d%d",&n,&m))
    {
		if(n==0&&m==0) break;
		len=floor(sqrt(2.0*m));
		for(;len>0;len--)
		{
			lena1=m-len*(len-1)/2;
			if(lena1%len==0) printf("[%d,%d]\n",lena1/len,lena1/len+len-1);
		}
		printf("\n");
	}
    return 0;
}

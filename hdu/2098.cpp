////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 18:30:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2098
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int prime(int n)
{
	int i;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return -1;
	}
	return 1;
}
int main()
{
    int n,i,count;
    while(~scanf("%d",&n))
    {
		if(n==0) break;
		count=0;
		for(i=3;i<n/2;i+=2)
		{
			if(prime(i)==1)
			{
				if(prime(n-i)==1) count++;
			}
		}
		printf("%d\n",count);
	}
    return 0;
}

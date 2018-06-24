////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 18:44:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2097
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,i,x,y,z;
    while(~scanf("%d",&n))
    {
		if(n==0) break;
		x=n/1000+n/100%10+n/10%10+n%10;
		for(i=n,y=0;i>0;)
		{
			y+=i%16;
			i/=16;
		}
		for(i=n,z=0;i>0;)
		{
			z+=i%12;
			i/=12;
		}
		if(x==y&&y==z) printf("%d is a Sky Number.\n",n);
		else printf("%d is not a Sky Number.\n",n);
	}
    return 0;
}

////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-05 14:02:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2186
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i,x,a,b,c,s;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			s=0;
			scanf("%d",&x);
			a=x/2;
			b=(x-a)*2/3;
			c=x-a-b;
			s=a/10+b/10+c/10;
			if(a%10!=0) s++;
			if(b%10!=0) s++;
			if(c%10!=0) s++;
			printf("%d\n",s);
		}
	}
	return 0;
}
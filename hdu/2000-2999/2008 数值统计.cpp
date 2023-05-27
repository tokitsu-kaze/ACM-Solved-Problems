////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-24 23:07:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1436KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,b,c,i;
	double m[100];
	while(~scanf("%d",&n)&&(n!=0))
	{
		a=0;
		b=0;
		c=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&m[i]);
			if(m[i]<0) a++;
			else if(m[i]==0) b++;
			else if(m[i]>0) c++;
		}
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}
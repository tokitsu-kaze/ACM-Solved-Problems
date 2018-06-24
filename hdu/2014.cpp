////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-28 21:10:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2014
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,i,x,y,z;
	double s;
	while(~scanf("%d",&n))
	{
		s=0;
		x=0;
		y=100;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			s=s+a;
			z=a;
			if(z>x) x=z;
			if(z<y) y=z;
		}
		printf("%.2lf\n",(s-x-y)/(n-2));
	}
	return 0;
}
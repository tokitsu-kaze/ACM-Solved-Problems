////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-29 22:46:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2076
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	double h,m,s,sum,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&h,&m,&s);
		if(h>12)
			h=h-12;
		m=m+s/60.0;
		a=m*6.0;
		h=h+m/60.0;
		b=h*30.0;
		sum=fabs(b-a);
		if(sum>180)
			sum=360-sum;
		printf("%d\n",(int)sum);
	}
	return 0;
}
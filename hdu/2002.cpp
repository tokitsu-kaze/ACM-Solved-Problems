////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-24 16:17:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2002
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1440KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#define PI 3.1415927
int main()
{
	double r;
	while(~scanf("%lf",&r))
	{
		printf("%.3lf\n",PI*pow(r,3)*4/3);
	}
	return 0;
}
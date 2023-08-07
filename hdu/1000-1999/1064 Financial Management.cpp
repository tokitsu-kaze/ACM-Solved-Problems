////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 13:35:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1448KB
//////////////////System Comment End//////////////////
#include <stdio.h> 
int main()
{
	int i=0;
	double a[13],s=0;
	while(i<12)
	{
		scanf("%lf",&a[i]);
		s=s+a[i];
		i++;
    }
	printf("$%.2f\n",s/12);
	return 0;
}

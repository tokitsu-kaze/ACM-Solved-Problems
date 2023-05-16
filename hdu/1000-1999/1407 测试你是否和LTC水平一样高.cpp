////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-05 11:50:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1407
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	int a,i,j,s;
	double h;
	while(~scanf("%d",&a))
	{
		s=0;
		for(i=1;i<sqrt(a);i++)
		{
			for(j=1;j<sqrt(a);j++)
			{
				h=sqrt(a-i*i-j*j);
				if(h==int(h)&&h!=0)
				{
					s=1;
					break;
				}
			}
			if(s==1) break;
		}
		printf("%d %d %.0lf\n",i,j,h);
	}
	return 0;
}
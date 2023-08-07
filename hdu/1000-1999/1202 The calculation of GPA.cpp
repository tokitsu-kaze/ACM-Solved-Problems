////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-23 19:50:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1202
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1444KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,d;
	double s,p,sum1,sum2;
    while(~scanf("%d",&n))
    {
		sum1=sum2=0;
		while(n--)
		{
			scanf("%lf%lf",&s,&p);
			if(p>=90) d=4;
			else if(p<90&&p>=80) d=3;
			else if(p<80&&p>=70) d=2;
			else if(p<70&&p>=60) d=1;
			else d=0;
			sum1+=s;
			sum2+=s*d;
		}
		if(sum2==0) printf("-1\n");
		else printf("%.2f\n",sum2*1.0/sum1);
    }
    return 0;
}

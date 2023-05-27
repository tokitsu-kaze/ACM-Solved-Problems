////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 15:12:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2056
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1444KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
int cmp(const void *a,const void *b)
{
	double c=*(double *)a;
	double d=*(double *)b;
	return c>d?1:-1;
}
int main()
{
    int i;
	double x1,y1,x2,y2,x[4],y[4];
    while(~scanf("%lf%lf",&x[0],&y[0]))
    {
    	for(i=1;i<4;i++)
    	{
			scanf("%lf%lf",&x[i],&y[i]);
		}
		x1=fabs(x[0]-x[1]);
		y1=fabs(y[0]-y[1]);
		x2=fabs(x[2]-x[3]);
		y2=fabs(y[2]-y[3]);
		qsort(x,4,sizeof(x[0]),cmp);
		qsort(y,4,sizeof(y[0]),cmp);
		if(x[3]-x[0]<x1+x2&&y[3]-y[0]<y1+y2) printf("%.2lf\n",(x[2]-x[1])*(y[2]-y[1]));
		else printf("0.00\n");
	}
    return 0;
}
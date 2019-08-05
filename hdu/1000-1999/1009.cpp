////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-15 16:22:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1009
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1440KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
struct trade
{
	int j;
	int f;
	double v;
}food[1001];
int cmp(const void *a,const void *b)
{
	struct trade *c=(struct trade *)a;
	struct trade *d=(struct trade *)b;
	return (c->v<d->v)?1:-1; 
}
int main()
{
    int m,n,i;
    double sum;
    while(~scanf("%d%d",&m,&n))
    {
		if(m==-1&&n==-1) break;
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&food[i].j,&food[i].f);
			if(food[i].f==0) food[i].v=food[i].j;
			else food[i].v=1.0*food[i].j/food[i].f;
		}
		qsort(food,n,sizeof(food[0]),cmp);
		for(i=0;i<n;i++)
		{
			if(food[i].f==0) sum+=food[i].f;
			if(m-food[i].f>=0)
			{
				sum+=food[i].j;
				m-=food[i].f;
			}
			else if(m!=0)
			{
				sum+=food[i].v*m;
				m=0;
			}
		}
		printf("%.3lf\n",sum);
    }
    return 0;
}
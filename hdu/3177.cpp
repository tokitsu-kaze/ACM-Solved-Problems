////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-15 18:44:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3177
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
struct scorpion
{
	int ai,bi;
}hole[1001];
int cmp(const void *a,const void *b)
{
	struct scorpion *c=(struct scorpion *)a;
	struct scorpion *d=(struct scorpion *)b;
	return (c->bi-c->ai)<(d->bi-d->ai)?1:-1;
}
int main()
{
    int t,n,v,i,flag;
    while(~scanf("%d",&t))
    {
		while(t--)
		{
			flag=0;
			scanf("%d%d",&v,&n);
			for(i=0;i<n;i++)
			{
				scanf("%d%d",&hole[i].ai,&hole[i].bi);
			}
			qsort(hole,n,sizeof(hole[0]),cmp);
			for(i=0;i<n;i++)
			{
				if(v>=hole[i].ai&&v>=hole[i].bi) v-=hole[i].ai;
				else
				{
					flag=1;
					break;
				}
			}
			if(flag==0) printf("Yes\n");
			else printf("No\n"); 
		}
    }
    return 0;
}
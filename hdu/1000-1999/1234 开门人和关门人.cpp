////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-15 16:55:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1234
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1432KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
struct record
{
	char id[21];
	int starth,startm,starts;
	int endh,endm,ends;
}men[10001];
int cmp1(const void *a,const void *b)
{
	struct record *c=(struct record *)a;
	struct record *d=(struct record *)b;
	if(c->starth<d->starth) return -1;
	else if(c->starth==d->starth)
	{
		if(c->startm<d->startm) return -1;
		else if(c->startm==d->startm)
		{
			if(c->starts<d->starts) return -1;
			else return 1;
		}
		else return 1;
	}
	else return 1;
}
int cmp2(const void *a,const void *b)
{
	struct record *c=(struct record *)a;
	struct record *d=(struct record *)b;
	if(c->endh<d->endh) return 1;
	else if(c->endh==d->endh)
	{
		if(c->endm<d->endm) return 1;
		else if(c->endm==d->endm)
		{
			if(c->ends<d->ends) return 1;
			else return -1;
		}
		else return -1;
	}
	else return -1;
}
int main()
{
    int n,m,i;
    while(~scanf("%d",&n))
    {
		while(n--)
		{
			scanf("%d",&m);
			for(i=0;i<m;i++)
			{
				scanf("%s",men[i].id);
				scanf("%d:%d:%d",&men[i].starth,&men[i].startm,&men[i].starts);
				scanf("%d:%d:%d",&men[i].endh,&men[i].endm,&men[i].ends);
			}
			qsort(men,m,sizeof(men[0]),cmp1);
			printf("%s ",men[0].id);
			qsort(men,m,sizeof(men[0]),cmp2);
			printf("%s\n",men[0].id);
		}
    }
    return 0;
}
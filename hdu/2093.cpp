////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 21:22:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2093
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1468KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct ACM
{
	char name[11];
	int score[100];
	int time;
	int count;
}stu[1001];
int cmp(const void *a,const void *b)
{
	ACM *c=(ACM *)a;
	ACM *d=(ACM *)b;
	if(c->count==d->count)
	{
		if(c->time==d->time) return strcmp(c->name,d->name)>0?1:-1;
		else return c->time>d->time?1:-1;
	}
	else return c->count<d->count?1:-1;
}
int main()
{
    int n,m,i,j=0,len,k,u,s=1;
    char c,d[101];
    scanf("%d%d",&n,&m);
	while(~scanf("%s",stu[j].name))
	{
		stu[j].count=0;
		stu[j].time=0;
		for(i=1;i<=2*n;)
		{
			scanf("%d",&stu[j].score[i]);
			if(stu[j].score[i]>0)
			{
				stu[j].count++;
				stu[j].time+=stu[j].score[i];
			}
			i++;
			c=getchar();
			if(c=='(')
			{
				scanf("%d",&stu[j].score[i]);
				getchar();
			}
			else stu[j].score[i]=0;
			stu[j].time+=m*stu[j].score[i];
			i++;
		}
		j++;
	}
	qsort(stu,j,sizeof(stu[0]),cmp);
	for(i=0;i<j;i++)
	{
		printf("%-10s %2d %4d\n",stu[i].name,stu[i].count,stu[i].time);
	}
    return 0;
}

////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-15 21:34:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1862
////Problem Title: 
////Run result: Accept
////Run time:702MS
////Run memory:3368KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
	char id[7];
	char name[9];
	int score;
}stu[100001];
int cmp1(const void *a,const void *b)
{
	 student *c=(student *)a;
	 student *d=(student *)b;
	return (strcmp(c->id,d->id))>0?1:-1;
}
int cmp2(const void *a,const void *b)
{
	 student *c=(student *)a;
	 student *d=(student *)b;
	if(strcmp(c->name,d->name)==0)
	{
		return (strcmp(c->id,d->id))>0?1:-1;
	}
	else return (strcmp(c->name,d->name))>0?1:-1;
}
int cmp3(const void *a,const void *b)
{
	 student *c=(student *)a;
	 student *d=(student *)b;
	if(c->score==d->score)
	{
		return (strcmp(c->id,d->id))>0?1:-1;
	}
	else return (c->score-d->score)>0?1:-1;
}
int main()
{
    int n,c,i,k=1;
    while(~scanf("%d%d",&n,&c))
    {
		if(n==0&&c==0) break;
		for(i=0;i<n;i++)
		{
			scanf("%s%s%d",stu[i].id,stu[i].name,&stu[i].score);
		}
		switch(c)
		{
			case 1:qsort(stu,n,sizeof(stu[0]),cmp1);break;
			case 2:qsort(stu,n,sizeof(stu[0]),cmp2);break;
			case 3:qsort(stu,n,sizeof(stu[0]),cmp3);break;
		}
		printf("Case %d:\n",k++);
		for(i=0;i<n;i++)
		{
			printf("%s %s %d\n",stu[i].id,stu[i].name,stu[i].score);
		}
    }
    return 0;
}
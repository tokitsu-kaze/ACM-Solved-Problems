////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-14 22:21:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1236
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:1492KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1005
struct STU
{
    char name[21];
    int m;
    int num[11];
    int sum;
}stu[MAX];

int cmp(const void *a,const void *b)
{
    struct STU *c=(struct STU *)a;
    struct STU *d=(struct STU *)b;
    if(c->sum!=d->sum)
    {return (d->sum-c->sum);}
    else
    {return (strcmp(c->name,d->name)>0)?1:-1;}
}
int main()
{
    int N,M,G,score[11],i,j,n;
    while(scanf("%d",&N)==1,N)
    {
        scanf("%d%d",&M,&G);
        for(i=1;i<=M;i++)
        {scanf("%d",&score[i]);}
        n=0;
        for(i=1;i<=N;i++)
        {
            scanf("%s %d",&stu[i].name,&stu[i].m);
            stu[i].sum=0;
            for(j=1;j<=stu[i].m;j++)
            {
                scanf("%d",&stu[i].num[j]);
                stu[i].sum+=score[stu[i].num[j]];
            }
            if(stu[i].sum>=G)
            {n++;}
        }
        qsort(stu+1,N,sizeof(stu[0]),cmp);
        printf("%d\n",n);
        for(i=1;i<=n;i++)
        {printf("%s %d\n",stu[i].name,stu[i].sum);}
    }
    return 0;
}
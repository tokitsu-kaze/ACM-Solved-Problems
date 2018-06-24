////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-23 18:19:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1070
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1428KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
struct milk
{
	char name[201];
	int price,volume;
	double v;
}mik[101];
int cmp(const void *a,const void *b)
{
	milk *c=(milk *)a;
	milk *d=(milk *)b;
	return c->v>d->v?1:-1;
}
int main()
{
	int t,n,i; 
    while(~scanf("%d",&t))
    {
		while(t--)
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%s%d%d",mik[i].name,&mik[i].price,&mik[i].volume);
				if(mik[i].volume<=1000&&mik[i].volume>=200)
				{ 
					mik[i].v=mik[i].price*1.0/(mik[i].volume/200);
				}
				else if(mik[i].volume>1000)
				{
					mik[i].v=mik[i].price*1.0/5;
				}
				else mik[i].v=0;
			}
			qsort(mik,n,sizeof(mik[0]),cmp);
			for(i=0;i<n;i++)
			{
				if(mik[i].volume>=200)
				{
					printf("%s\n",mik[i].name);
					break;
				}
			}
		}
    }
    return 0;
}
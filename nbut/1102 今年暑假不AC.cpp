#include <stdio.h>
#include <stdlib.h>
struct tv
{
	int start,end;
}time[101];
int cmp(const void *a,const void *b)
{
	tv *c=(tv *)a;
	tv *d=(tv *)b;
	return (c->end>d->end)?1:-1;
}
int main()
{
    int n,i,sum,end;
    while(~scanf("%d",&n))
    {
		if(n==0) break;
		sum=1;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&time[i].start,&time[i].end);
		}
		qsort(time,n,sizeof(time[0]),cmp);
		end=time[0].end;
		for(i=1;i<n;i++)
		{
			if(time[i].start>=end)
			{
				sum++;
				end=time[i].end;
			}
		}
		printf("%d\n",sum);
    }
    return 0;
}
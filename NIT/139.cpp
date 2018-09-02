#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
using namespace std;
struct room
{
	int a,b;
}r[20010];
int cmp(const void *a,const void *b)
{
	struct room *c=(struct room *)a;
	struct room *d=(struct room *)b;
	if(c->a==d->a) return c->b>d->b;
	else return c->a>d->a?1:-1;
}
int main()
{
	int t,i,j,count,max;
	while(cin>>t)
	{
		max=INT_MIN;
		for(i=0;i<t*2;i++)
		{
			scanf("%d",&r[i].a);
			if(i%2==0) r[i].b=1;
			else r[i].b=0;
		}
		qsort(r,t*2,sizeof(r[0]),cmp);
		count=0;
		for(i=0;i<t*2;i++)
		{
			if(r[i].b) count++;
			else count--;
			if(count>max) max=count;
		}
		cout<<max<<endl;
	}
    return 0;
}
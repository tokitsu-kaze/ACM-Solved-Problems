#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;
struct bis
{
	int a,b,v;
}bis[21];
int cmp(const void *a,const void *b)
{
	struct bis *c=(struct bis*)a;
	struct bis *d=(struct bis*)b;
	return c->v<d->v?1:-1;
}
int main()
{
	int n,m,x,t,i,sum,s;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>m>>x;
			for(i=0;i<m;i++)
			{
				cin>>bis[i].a>>bis[i].b;
				s=n/bis[i].a*bis[i].a;
				bis[i].v=n/bis[i].a*(bis[i].b-bis[i].a)-s*(1.0*x/100);
			}
			qsort(bis,m,sizeof(bis[0]),cmp);
			sum=(int)(bis[0].v);
			if(sum<0) sum=0;
			printf("%d\n",sum);
		}
	}
	return 0;
}
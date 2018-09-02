#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;
struct race
{
	char name[101];
	int v,mv;
	double t;
}r[1001];
int cmp(const void *a,const void *b)
{
	struct race *c=(struct race *)a;
	struct race *d=(struct race *)b;
	if(c->t==d->t)
	{
		if(c->mv==d->mv) return strcmp(c->name,d->name)>0?1:-1;
		else return c->mv<d->mv?1:-1;
	}
	
	else return c->t>d->t?1:-1;
}
int main()  
{  
    int m,n,s,i,count; 
    while(cin>>m)  
    {
        while(m--)
        {
			cin>>n>>s;
			for(i=0;i<n;i++)
			{
				scanf("%s %d%d",r[i].name,&r[i].v,&r[i].mv);
				r[i].t=1.0*s/r[i].v;
			}
			qsort(r,n,sizeof(r[0]),cmp);
		//	cout<<r[0].name;
			count=1;
			for(i=1;i<n;i++)
			{
				if(r[i].t==r[0].t&&r[i].mv==r[0].mv) count++;
			}
		//	cout<<count;
			if(count==1) printf("YES\n%s\n",r[0].name);
			else
			{
				cout<<"NO"<<endl;
				for(i=0;i<count;i++)
				{
					cout<<r[i].name<<endl;
				}
			}
			if(m) cout<<endl;
		}
    }  
    return 0;
} 
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int m,v;
	friend bool operator <(node a,node b)
	{
		return 1.0*a.v/a.m>1.0*b.v/b.m;
	}
}a[105];
int main()
{
	int n,t,i;
	double ans;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].m,&a[i].v);
	sort(a+1,a+1+n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(a[i].m<=t)
		{
			t-=a[i].m;
			ans+=a[i].v;
		}
		else
		{
			ans+=(1.0*a[i].v/a[i].m)*t;
			t=0;
			break;
		}
	}
	printf("%.2f\n",ans);
	return 0;
}

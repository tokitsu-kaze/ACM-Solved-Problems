#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-7;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int tag;
	ll x,v;
	void input()
	{
		scanf("%lld%lld%d",&x,&v,&tag);
	}
}a[MAX];
int n,s;
bool check(double t)
{
	int i;
	ll l1,r1,l2,r2;
	r1=r2=0;
	l1=l2=1e6+1;
	for(i=0;i<n;i++)
	{
		if(a[i].tag==1)
		{
			if(a[i].v*t>=a[i].x)
			{
				l1=0;
				r1=1e6;
			}
			else if((a[i].v+s)*t>=a[i].x)
			{
				l1=min(l1,a[i].x);
				r1=max(r1,a[i].x+(ll)(((s+a[i].v)*t-a[i].x)*(s-a[i].v))/s);
			}
		}
		else
		{
			if(a[i].v*t>=1e6-a[i].x)
			{
				l2=0;
				r2=1e6;
			}
			else if((a[i].v+s)*t>=1e6-a[i].x)
			{
				r2=max(r2,a[i].x);
				l2=min(l2,a[i].x-(ll)(((s+a[i].v)*t-1e6+a[i].x)*(s-a[i].v))/s);
			}
		}
	}
	if(l1>r2||l2>r1) return 0;
	return 1;
}
int main()
{
	int i;
	while(~scanf("%d%d",&n,&s))
	{
		for(i=0;i<n;i++)
		{
			a[i].input();
		}
		double l,r,mid;
		l=0;
		r=1e6;
		while(r-l>eps)
		{
			mid=(l+r)/2;
			if(check(mid)) r=mid;
			else l=mid;
		}
		printf("%.10lf\n",r);
	}
	return 0;
}
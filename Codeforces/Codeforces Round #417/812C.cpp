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
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e4;
struct node
{
	ll p,v;
	friend bool operator <(node a,node b)
	{
		return a.v<b.v;
	}
}a[MAX],b[MAX];
ll cal(ll n,ll s)
{
	ll i,res=0;
	for(i=1;i<=s;i++)
	{
		b[i].v=a[i].p*n+a[i].v;
	}
	sort(b+1,b+1+s);
	for(i=1;i<=n;i++)
	{
		res+=b[i].v;
	}
	return res;
}
int main()
{
	ll n,s,i;
	while(~scanf("%lld%lld",&n,&s))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].v);
			a[i].p=i;
		}
		ll l,r,mid,tm;
		l=0;
		r=n;
		while(r-l>0)
		{
			mid=(l+r)>>1;
			tm=cal(mid+1,n);
			if(tm<=s) l=mid+1;
			else r=mid;
		}
		printf("%lld %lld\n",l,cal(l,n));
	}
	return 0;
}
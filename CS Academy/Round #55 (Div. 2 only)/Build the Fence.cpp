#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll a[MAX],n;
bool check(ll v,ll k)
{
	ll res=0,i;
	for(i=0;i<n;i++) res+=a[i]/v;
	if(res>=k) return 1;
	return 0;
}
int main()
{
	ll k,i,s,l,r,mid;
	while(~scanf("%lld%lld",&n,&k))
	{
		s=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			s+=a[i];
		}
		l=1;
		r=s/k;
		if(r==0)
		{
		    puts("0");
		    continue;
		}
		while(l<r)
		{
			mid=(l+r)>>1;
			if(check(mid+1,k)) l=mid+1;
			else r=mid;
		}
		if(check(l,k)) printf("%lld\n",l);
		else puts("0");
	}
	return 0;
}
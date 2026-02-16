#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll x,y,k;
int ck(ll n)
{
	int i;
	for(i=0;i<x;i++) n-=n/y;
	return n>=k;
}
int main()
{
	int T;
	ll l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&x,&y,&k);
		l=1;
		r=1e12;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		if(ck(l)) printf("%lld\n",l);
		else puts("-1");
	}
	return 0;
}

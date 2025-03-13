#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int n;
ll m,p[MAX];
ll cal(ll x,bool ansflag=false)
{
	int i;
	ll res,k,now,sq;
	res=0;
	now=m;
	vector<ll> tmp;
	for(i=1;i<=n;i++)
	{
		sq=sqrt(now/p[i]);
		while(sq*sq*p[i]<now) sq++;
		while(sq>0 && sq*sq*p[i]>now) sq--;
		k=(x/p[i]+1)/2;
		if(!ansflag && k>sq) return LLINF;
		k=min(k,sq);
		res+=k;
		now-=k*k*p[i];
		tmp.push_back((k+1)*(k+1)*p[i]-k*k*p[i]);
	}
	if(ansflag)
	{
		sort(tmp.begin(),tmp.end());
		for(auto &it:tmp)
		{
			if(now>=it)
			{
				res++;
				now-=it;
			}
		}
	}
	return res;
}
/*
p,3p,5p
(2k-1)p
*/
int main()
{
	int i;
	ll l,r,mid,res;
	scanf("%d%lld",&n,&m);
	for(i=1;i<=n;i++) scanf("%lld",&p[i]);
	sort(p+1,p+1+n);
	l=0;
	r=1e18;
	while(l<r)
	{
		mid=(l+r)>>1;
		res=cal(mid+1);
		if(res<LLINF && res>=cal(mid)) l=mid+1;
		else r=mid;
	}
	printf("%lld\n",cal(l,true));
	return 0;
}
/*
6 3
1 1 1 1 1 1
2 25
1 1
*/

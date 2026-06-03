#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e6+10;
map<int,int> mp;
int get_phi(int n)
{
	if(mp.count(n)) return mp[n];
	int ans,i;
	ans=n;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans=ans-ans/i;
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans=ans-ans/n;
	return mp[n]=ans;
}
ll qpow(ll a,ll b,ll p)
{
	if(p==1) return 0;
	ll res=1;
	while(b>0)
	{
		if(b&1) res*=a;
		a*=a;
		b>>=1;
		if(res>=p) res=res%p+p;
		if(a>=p) a=a%p+p;
	}
	return res;
}
int w[MAX];
ll gao(int x,int r,int p)
{
	if(x==r||p==1) return w[x]<p?w[x]:w[x]%p+p;
	return qpow(w[x],gao(x+1,r,get_phi(p)),p);
}
int main()
{
	const int p=10007;
	mp.clear();
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&w[i]);
	printf("%lld\n",gao(1,n,p)%p);
	return 0;
}
//CF906D

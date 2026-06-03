#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Fenwick_Tree
{
	#define type ll
	type bit[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		for(;x;x-=lowbit(x)) res=max(res,bit[x]);
		return res;
	}
	void upd(int x,type v)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=max(bit[x],v);
	}
	type ask(int r)
	{
		return get(r);
	}
	#undef type
}tr;
int h[MAX],a[MAX];
ll dp[MAX];
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&h[i]);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	tr.init(n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		dp[i]=tr.ask(h[i])+a[i];
		ans=max(ans,dp[i]);
		tr.upd(h[i],dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}

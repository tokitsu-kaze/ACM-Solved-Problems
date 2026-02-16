#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=998244353;
struct Fenwick_Tree
{
	#define type ll
	type bit[MAX],tmp[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,type *a)
	{
		n=_n;
		tmp[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=a[i];
			tmp[i]+=tmp[i-1];
			bit[i]=tmp[i]-tmp[i-lowbit(i)];
		}
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		for(;x;x-=lowbit(x)) (res+=bit[x])%=mod;
		return res;
	}
	void upd(int x,type v)
	{
		for(;x<=n;x+=lowbit(x)) (bit[x]+=v)%=mod;
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return (get(r)-get(l-1)+mod)%mod;
	}
	void clear(int x)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=0;
	}
	#undef type
}tr[2],trcnt;
ll dp[MAX][2];
int main()
{
	int n,i,x;
	ll ans;
	scanf("%d",&n);
	tr[0].init(n);
	tr[1].init(n);
	trcnt.init(n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		dp[i][0]=dp[i][1]=0;
		dp[i][1]+=trcnt.ask(1,x-1);
		dp[i][1]+=tr[0].ask(1,x-1);
		dp[i][1]+=tr[1].ask(1,x-1);
		dp[i][1]%=mod;
		dp[i][0]+=tr[0].ask(x+1,n);
		dp[i][0]+=tr[1].ask(x+1,n);
		dp[i][0]%=mod;
		ans=(ans+dp[i][0])%mod;
		tr[0].upd(x,dp[i][0]);
		tr[1].upd(x,dp[i][1]);
		trcnt.upd(x,1);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
dp[i][0/1]表示是在下降还是在上升 
下降趋势时可以记录答案 
*/

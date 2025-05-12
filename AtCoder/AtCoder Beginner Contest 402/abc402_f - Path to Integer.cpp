#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int mod;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int n,limt;
ll ans;
int mp[22][22];
set<int> res[22][22];
void dfs1(int x,int y,ll now,int len)
{
	if(x<1||y<1||x>n||y>n) return;
	now=(now*10LL+mp[x][y])%mod;
	if(len==limt)
	{
		res[x][y].insert(now*qpow(10,2*n-1-len)%mod);
		return;
	}
	dfs1(x+1,y,now,len+1);
	dfs1(x,y+1,now,len+1);
}
void dfs2(int x,int y,ll now,ll sd,int len)
{
	if(x<1||y<1||x>n||y>n) return;
	if(len==limt+1)
	{
		ans=max(ans,(now+*res[x][y].rbegin())%mod);
		auto it=res[x][y].upper_bound(mod-now-1);
		if(it!=res[x][y].begin())
		{
			it--;
			ans=max(ans,now+*it);
		}
		return;
	}
	now=(now+sd*mp[x][y])%mod;
	dfs2(x-1,y,now,sd*10%mod,len+1);
	dfs2(x,y-1,now,sd*10%mod,len+1);
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&mod);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&mp[i][j]);
			res[i][j].clear();
		}
	}
	if(n==1) return 0*printf("%d\n",mp[1][1]%mod);
	limt=(2*n-1)/2;
	dfs1(1,1,0,1);
	limt=(2*n-1)-limt;
	ans=0;
	dfs2(n,n,0,1,1);
	printf("%lld\n",ans);
	return 0;
}

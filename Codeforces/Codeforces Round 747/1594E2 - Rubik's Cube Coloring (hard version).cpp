#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
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
map<int,int> col;
vector<int> mp[MAX];
ll dp[MAX][8];
void dfs(int x)
{
	int i,j;
	ll sum;
	memset(dp[x],0,sizeof dp[x]);
	if(col.count(x)) dp[x][col[x]]=1;
	else
	{
		for(i=1;i<=6;i++) dp[x][i]=1;
	}
	for(auto &to:mp[x])
	{
		dfs(to);
		for(i=1;i<=6;i++)
		{
			sum=0;
			for(j=1;j<=6;j++)
			{
				if(i==j || i+j==7) continue;
				sum+=dp[to][j];
			}
			sum%=mod;
			dp[x][i]=dp[x][i]*sum%mod;
		}
	}
}
int main()
{
	map<string,int> colid;
	colid["white"]=1;
	colid["green"]=2;
	colid["red"]=3;
	colid["orange"]=4;
	colid["blue"]=5;
	colid["yellow"]=6;
	int k,n,i,tot;
	ll x,ans;
	char s[12];
	map<ll,int> id,in;
	tot=0;
	scanf("%d%d",&k,&n);
	for(i=1;i<=k*n;i++) mp[i].clear();
	col.clear();
	for(i=1;i<=n;i++)
	{
		scanf("%lld%s",&x,s);
		if(!id.count(x)) id[x]=++tot;
		col[id[x]]=colid[s];
		while(x>1 && !in.count(x))
		{
			in[x]=1;
			if(!id.count(x>>1)) id[x>>1]=++tot;
			mp[id[x>>1]].push_back(id[x]);
			x>>=1;
		}
	}
	dfs(id[1]);
	ans=0;
	for(i=1;i<=6;i++) ans=(ans+dp[id[1]][i])%mod;
	printf("%lld\n",ans*qpow(4,(1LL<<k)-1-tot)%mod);
	return 0;
}
/*
建出虚树，节点O(kn)，然后直接dp就行了。
*/

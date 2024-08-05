#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
const int mod=998244353;
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
ll inv(ll x){return qpow(x,mod-2);}
vector<int> mp[MAX];
int v[MAX],pos[MAX],vis[MAX],fa[MAX];
ll dp[MAX];
void dfs(int x,int pre)
{
	fa[x]=pre;
	dp[x]=1;
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		dfs(to,x);
		dp[x]=dp[x]*(dp[to]+1)%mod;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,n,i,a,b,x,pre,cnt;
	ll now,ans;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>v[i];
			mp[i].clear();
			pos[v[i]]=i;
			vis[i]=0;
		}
		for(i=1;i<n;i++)
		{
			cin>>a>>b;
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		dfs(pos[0],0);
		now=1;
		ans=0;
		vis[pos[0]]=1;
		now=dp[pos[0]];
		for(i=1;i<n;i++)
		{
			x=pos[i];
			if(vis[x]) continue;
			cnt=0;
			while(x&&!vis[x])
			{
				if(!vis[fa[x]])
				{
					cnt=dp[fa[x]]*inv(dp[x]+1)%mod*(cnt+1)%mod;
				}
				pre=x;
				x=fa[x];
			}
			now=now*inv(dp[pre]+1)%mod;
			ans=(ans+now*(cnt+1)%mod*i)%mod;
//			cout<<i<<" "<<cnt<<" "<<now<<endl;
			x=pos[i];
			pre=-1;
			while(x&&!vis[x])
			{
				for(auto &to:mp[x])
				{
					if(to==pre) continue;
					if(to==fa[x]) continue;
					now=now*(dp[to]+1)%mod;
//					cout<<to<<" "<<now<<endl;
				}
				vis[x]=1;
				pre=x;
				x=fa[x];
			}
//			cout<<i<<" "<<ans<<" "<<now<<endl;
		}
		ans=(ans+n)%mod;
		cout<<ans<<"\n";
	}
	return 0;
}

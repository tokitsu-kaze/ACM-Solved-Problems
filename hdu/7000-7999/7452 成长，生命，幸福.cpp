#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
const int mod=1e9+7;
struct Tree_Diameter
{
	int fa[MAX],rt;
	ll mx;
	void dfs(int x,int pre,ll h,vector<int> *mp,ll *v)
	{
		fa[x]=pre;
		h+=v[x];
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dfs(to,x,h,mp,v);
		}
		if(h>mx)
		{
			mx=h;
			rt=x;
		}
	}
	vector<int> get_tree_diameter(vector<int> *mp,ll *v)
	{
		fa[0]=0;
		rt=1;
		mx=0;
		dfs(rt,0,0,mp,v);
		mx=0;
		dfs(rt,0,0,mp,v);
		vector<int> res;
		while(rt)
		{
			res.push_back(rt);
			rt=fa[rt];
		}
		return res;
	}
}td;
ll v[MAX];
ll spow(ll a,int b)
{
	ll res=1;
	for(int i=0;i<b;i++) res*=a;
	return res;
}
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
vector<int> mp[MAX];
int main()
{
	int t,n,m,i,j,a,b,cnt,k;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		assert(m>=1);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		for(i=1;i<=n;i++) v[i]=mp[i].size();
		if(m==1)
		{
			vector<int> res=td.get_tree_diameter(mp,v);
			ans=0;
			for(auto &it:res) ans+=v[it];
			printf("%lld\n",ans);
			continue;
		}
		k=min(10,m);
		for(i=1;i<=n;i++)
		{
			cnt=mp[i].size();
			if(cnt<=1) v[i]=cnt;
			else v[i]=1LL*(cnt-1)*(spow(2,k)-1)+1;
		}
		vector<int> res=td.get_tree_diameter(mp,v);
		ans=0;
		for(auto &it:res)
		{
			cnt=mp[it].size();
			if(cnt<=1) ans=(ans+cnt)%mod;
			else ans=(ans+1LL*(cnt-1)*(qpow(2,m)-1)+1)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

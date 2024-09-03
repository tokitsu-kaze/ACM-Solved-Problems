#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct Long_Chain_Decomposition
{
	#define type ll
	vector<int> *mp;
	int son[MAX],top[MAX];
	type dep[MAX],v[MAX];
	void dfs1(int x,int pre)
	{
		son[x]=-1;
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dfs1(to,x);
			if(son[x]==-1||dep[to]>dep[son[x]]) son[x]=to;
		}
		if(son[x]!=-1) dep[x]=dep[son[x]]+v[x];
		else dep[x]=v[x];
	}
	void dfs2(int x,int tp,int pre)
	{
		top[x]=tp;
		if(son[x]==-1) return;
		dfs2(son[x],tp,x);
		for(auto &to:mp[x])
		{
			if(to==pre||to==son[x]) continue;
			dfs2(to,to,x);
		}
	}
	ll res[MAX],tmp[MAX];
	int tot;
	void dfs(int x,int pre)
	{
		tmp[x]=0;
		tmp[top[x]]+=v[x];
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dfs(to,x);
		}
		if(x==top[x]) res[tot++]=tmp[x];
	}
	void work(int rt,vector<int> *_mp,int k)
	{
		mp=_mp;
		dfs1(rt,0);
		dfs2(rt,rt,0);
		tot=0;
		dfs(1,0);
		sort(res,res+tot);
		reverse(res,res+tot);
		ll ans=0;
		for(int i=0;i<min(tot,k);i++) ans+=res[i];
		printf("%lld\n",ans);
	}
	#undef type
}lcd;
/*
lcd.work(rt,mp);
*/
vector<int> mp[MAX];
int main()
{
	int n,k,i,a,b;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		scanf("%lld",&lcd.v[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	lcd.work(1,mp,k);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct node{int to;ll w;};
struct Long_Chain_Decomposition
{
	#define type ll
	vector<node> *mp;
	int son[MAX],top[MAX];
	type dep[MAX],v[MAX];
	void dfs1(int x,int pre)
	{
		son[x]=-1;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==pre) continue;
			v[to]=it.w;
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
		for(auto &it:mp[x])
		{
			int to=it.to;
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
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==pre) continue;
			dfs(to,x);
		}
		if(x==top[x]) res[tot++]=tmp[x];
	}
	void work(int n,int rt,vector<node> *_mp)
	{
		mp=_mp;
		dfs1(rt,0);
		dfs2(rt,rt,0);
		tot=0;
		dfs(rt,0);
		sort(res,res+tot);
		reverse(res,res+tot);
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			if(i<tot) ans+=2*res[i];
			printf("%lld\n",ans);
		}
	}
	#undef type
}lcd;
/*
lcd.work(n,rt,mp);
*/
vector<node> mp[MAX];
int main()
{
	int n,i,a,b,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
	}
	lcd.work(n,1,mp);
	return 0;
}

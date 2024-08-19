#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e4+10;
const int MAXQ=1e7+10;
struct Q{int k,id;};
vector<Q> qst;
int res[MAX];
struct tree_divide
{
	#define type int
	struct edge{int to;type w;};
	vector<edge> mp[MAX];
	bool vis[MAX];
	int sz[MAX],mx[MAX],sum,rt,n;
	void init(int _n)
	{
		int i;
		n=_n;
		for(i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type w){mp[x].push_back({y,w});}
	void get_centroid(int x,int fa)
	{
		sz[x]=1;
		mx[x]=0;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==fa||vis[to]) continue;
			get_centroid(to,x);
			sz[x]+=sz[to];
			mx[x]=max(mx[x],sz[to]);
		}
		mx[x]=max(mx[x],sum-sz[x]);
		if(mx[x]<mx[rt]) rt=x;
	}
	void get_sz(int x,int fa)
	{
		sz[x]=1;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==fa||vis[to]) continue;
			get_sz(to,x);
			sz[x]+=sz[to];
		}
	}
	int d[MAX],totd;
	void get_dis(int x,int fa,type h)
	{
		if(h>=MAXQ) return;
		d[++totd]=h;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==fa||vis[to]) continue;
			get_dis(to,x,h+it.w);
		}
	}
	int del[MAX],totdel;
	bool flag[MAXQ];
	void cal(int x)
	{
		int i,j;
		flag[0]=1;
		totdel=0;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(vis[to]) continue;
			totd=0;
			get_dis(to,x,it.w);
			for(i=1;i<=totd;i++)
			{
				for(auto &q:qst)
				{
					if(q.k>=d[i]) res[q.id]|=flag[q.k-d[i]];
				}
			}
			for(i=1;i<=totd;i++)
			{
				del[++totdel]=d[i];
				flag[d[i]]=1;
			}
		}
		for(i=1;i<=totdel;i++) flag[del[i]]=0;
	}
	void divide(int x)
	{
		vis[x]=1;
		cal(x);
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(vis[to]) continue;
			get_sz(to,-1);
			rt=0;
			mx[rt]=sum=sz[to];
			get_centroid(to,-1);
			divide(rt);
		}
	}
	void work()
	{
		int i;
		for(i=0;i<=n;i++) vis[i]=0;
		for(i=0;i<MAXQ;i++) flag[i]=0;
		rt=0;
		mx[rt]=sum=n;
		get_centroid(1,-1);
		divide(rt);
	}
	#undef type
}tdv;
int main()
{
	int n,m,i,a,b,c;
	scanf("%d%d",&n,&m);
	tdv.init(n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		tdv.add_edge(a,b,c);
		tdv.add_edge(b,a,c);
	}
	qst.clear();
	for(i=1;i<=m;i++)
	{
		res[i]=0;
		scanf("%d",&a);
		qst.push_back({a,i});
	}
	tdv.work();
	for(i=1;i<=m;i++)
	{
		if(res[i]) puts("AYE");
		else puts("NAY");
	}
	return 0;
}
/*
11 1
6 7 1
6 8 1
7 9 1
7 10 1
8 11 1
1 2 1
1 3 1
2 4 1
2 5 1
3 6 1
2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
struct ST_table
{
	#define type int
	static const int N=MAX*18;
	static const int LOG=21;
	type v[N];
	int lg[N],bin[LOG],pmx[LOG][N];
	int pmax(const int &a,const int &b){return v[a]>v[b]?a:b;}
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			pmx[0][i]=i;
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				pmx[j][i]=pmax(pmx[j-1][i],pmx[j-1][i+bin[j-1]]);
			}
		}
	}
	int ask_pmax(int l,int r)
	{
		int t=lg[r-l+1];
		return pmax(pmx[t][l],pmx[t][r-bin[t]+1]);
	}
	#undef type
}rmq;
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
	type dis[MAX*18];
	int l[MAX*18],r[MAX*18],tot,nowl,nowr;
	void get_dis(int x,int fa,type h)
	{
		dis[++tot]=h;
		l[tot]=nowl;
		r[tot]=nowr;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==fa||vis[to]) continue;
			get_dis(to,x,h+it.w);
		}
	}
	void cal(int x)
	{
		int i,j;
		nowr=tot;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(vis[to]) continue;
			get_sz(to,x);
			nowr+=sz[to];
		}
		nowr++;
		nowl=tot+1;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(vis[to]) continue;
			get_sz(to,x);
			nowl+=sz[to];
			get_dis(to,x,it.w);
		}
		assert(nowl==nowr);
		dis[++tot]=0;
		l[tot]=r[tot]=nowl;
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
		rt=0;
		mx[rt]=sum=n;
		get_centroid(1,-1);
		tot=0;
		divide(rt);
	}
	#undef type
}tdv;
/*
tdv.init(n);
tdv.add_edge(x,y,w)   // x -> y
tdv.work();
*/
struct node
{
	int id,l,r,x;
	ll v;
	friend bool operator <(node a,node b)
	{
		return rmq.v[a.id]+rmq.v[a.x]<rmq.v[b.id]+rmq.v[b.x];
	}
};
int main()
{
	int n,k,i,a,b,c,mxpos;
	scanf("%d%d",&n,&k);
	tdv.init(n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		tdv.add_edge(a,b,c);
		tdv.add_edge(b,a,c);
	}
	tdv.work();
	priority_queue<node> q;
	rmq.work(tdv.tot,tdv.dis);
	for(i=1;i<=tdv.tot;i++)
	{
		if(tdv.l[i]) q.push({i,tdv.l[i],tdv.r[i],rmq.ask_pmax(tdv.l[i],tdv.r[i])});
	}
	while(k--)
	{
		auto it=q.top();
		q.pop();
		printf("%d\n",rmq.v[it.id]+rmq.v[it.x]);
		if(it.x>it.l) q.push({it.id,it.l,it.x-1,rmq.ask_pmax(it.l,it.x-1)});
		if(it.x<it.r) q.push({it.id,it.x+1,it.r,rmq.ask_pmax(it.x+1,it.r)});
	}
	return 0;
}

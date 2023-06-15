#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const ll LLINF=0x3f3f3f3f3f3f3f3fll;
const int MAX=1e5+10;
struct Dijkstra
{
	#define type ll
	const type inf=LLINF;
	struct node
	{
		int id;
		type v;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	static const int N=MAX;
	vector<node> mp[N];
	type dis[N];
	int n,vis[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){ mp[x].pb({y,v});}
	void work(int s)
	{
		int i,to;
		type w;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		dis[s]=1;
		q.push({s,type(0)});
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id]) continue;
			vis[t.id]=1;// this node has already been extended
			for(auto &it:mp[t.id])
			{
				to=it.id;
				w=it.v;
				if(dis[to]>dis[t.id]+w)
				{
					dis[to]=dis[t.id]+w;
					if(!vis[to]) q.push({to,dis[to]}); 
				}
			}
		}
	}
	#undef type
}dij;
//求[l,r]中有多少个 b 满足 sum{ai*xi}=b, xi>=0 
ll congruent_short_path(vector<int> a,ll l,ll r)
{
	int n,i,j;
	ll res;
	n=a.size();
	sort(a.begin(),a.end());
	dij.init(a[0]);
	for(i=0;i<a[0];i++)
	{
		for(j=1;j<n;j++)
		{
			dij.add_edge(i,(i+a[j])%a[0],a[j]);
		}
	}
	dij.work(0);
	res=0;
	for(i=0;i<a[0];i++)
	{
		if(dij.dis[i]==dij.inf) continue;
		if(dij.dis[i]<=r) res+=(r-dij.dis[i])/a[0]+1;
		if(dij.dis[i]<=l-1) res-=((l-1)-dij.dis[i])/a[0]+1;
	}
	return res;
}
int main()
{
	int x,y,z;
	ll h;
	scanf("%lld",&h);
	scanf("%d%d%d",&x,&y,&z);
	printf("%lld\n",congruent_short_path(vector<int>{x,y,z},1,h));
	return 0;
}

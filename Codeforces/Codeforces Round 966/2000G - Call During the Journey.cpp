#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e6+10;
int t0,t1,t2;
int check_cal(ll s,ll len)
{
	if(s>t1 && s<t2) return 0;
	if(s<t2 && s+len>t1) return 0;
	return 1;
}
struct Dijkstra
{
	#define type ll
	const type inf=LLINF;
	struct node
	{
		int id;
		type v,v2;
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
	void add_edge(int x,int y,type v,type v2){mp[x].push_back({y,v,v2});}
	void work(int s,int x)
	{
		int i,to;
		type w,w2;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		dis[s]=x;
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
				w2=it.v2;
				if(!check_cal(dis[t.id],w))
				{
					if(dis[to]>dis[t.id]+w2)
					{
						dis[to]=dis[t.id]+w2;
						if(!vis[to]) q.push({to,dis[to]});
					}
					if(dis[to]>t2+w)
					{
						dis[to]=t2+w;
						if(!vis[to]) q.push({to,dis[to]});
					}
				}
				else
				{
					if(dis[to]>dis[t.id]+w)
					{
						dis[to]=dis[t.id]+w;
						if(!vis[to]) q.push({to,dis[to]});
					}
				}
			}
		}
	}
	#undef type
}dij;
int n;
int ck(int x)
{
	dij.work(1,x);
	return dij.dis[n]<=t0;
}
int main()
{
	int t,m,i,a,b,c,d,l,r,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		dij.init(n);
		scanf("%d%d%d",&t0,&t1,&t2);
		while(m--)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			dij.add_edge(a,b,c,d);
			dij.add_edge(b,a,c,d);
		}
		l=0;
		r=t0;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		if(ck(l)) printf("%d\n",l);
		else puts("-1");
	}
	return 0;
}

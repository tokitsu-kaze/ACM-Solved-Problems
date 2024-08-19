#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
//x is a prime if prime[x]==x(x>=2)
int p[MAX],tot,prime[MAX];
void init_prime(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
struct Dinic
{
	#define type int
	const type inf=INF;
	static const int N=105;
	struct node
	{
		int from,to;
		type cap,flow;
		node(int u,int v,type c,type f):from(u),to(v),cap(c),flow(f){}
	};
	int n,s,t;
	vector<node> edge;
	vector<int> mp[N];
	int vis[N],dist[N],id[N];
	void init(int _n)
	{
		n=_n;
		edge.clear();
		for(int i=0;i<=n;i++)
		{
			mp[i].clear();
			id[i]=dist[i]=vis[i]=0;
		}
	}
	void add_edge(int from,int to,type cap)
	{
		edge.push_back(node(from,to,cap,0));
		edge.push_back(node(to,from,0,0));
		int m=edge.size();
		mp[from].push_back(m-2);
		mp[to].push_back(m-1);
	}
	bool bfs()
	{
		int i,x;
		memset(vis,0,sizeof vis);
		queue<int>q;
		q.push(s);
		dist[s]=0;
		vis[s]=1;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			for(i=0;i<mp[x].size();i++)
			{
				node &e=edge[mp[x][i]];
				if(!vis[e.to]&&e.cap>e.flow)
				{
					vis[e.to]=1;
					dist[e.to]=dist[x]+1;
					q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	type dfs(int x,type a)
	{
		if(x==t||!a) return a;
		type flow=0,f;
		for(int &i=id[x];i<mp[x].size();i++)
		{
			node &e=edge[mp[x][i]];
			if(dist[x]+1==dist[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0)
			{
				e.flow+=f;
				edge[mp[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
				if(!a) break;
			}
		}
		return flow;
	}
	type max_flow(int _s,int _t)
	{
		s=_s;
		t=_t;
		type res=0;
		while(bfs())
		{
			for(int i=0;i<=n;i++) id[i]=0;
			res+=dfs(s,inf);
		}
		return res;
	}
	#undef type
}dc; 
/*
O(n^2*m)
bipartite graph: O(m*sqrt(n))

dc.init(n);
dc.add_edge(a,b,cap); a,b: 1~n
*/
int pw[105],c[105],lv[105],n,k;
int ck(int x)
{
	int i,j,s,t,sum,res,mx1;
	s=n+1;
	t=s+1;
	dc.init(t);
	mx1=0;
	sum=0;
	for(i=1;i<=n;i++)
	{
		if(lv[i]>x) continue;
		if(c[i]==1) mx1=max(mx1,pw[i]);
		else sum+=pw[i];
	}
	sum+=mx1;
	for(i=1;i<=n;i++)
	{
		if(lv[i]>x) continue;
		if(c[i]&1)
		{
			if(c[i]==1)
			{
				if(pw[i]==mx1) dc.add_edge(s,i,pw[i]);
			}
			else dc.add_edge(s,i,pw[i]);
		}
		else dc.add_edge(i,t,pw[i]);
	}
	for(i=1;i<=n;i++) // odd
	{
		if(lv[i]>x) continue;
		if(c[i]%2==0) continue;
		if(c[i]==1 && pw[i]!=mx1) continue;
		for(j=1;j<=n;j++) // even
		{
			if(lv[j]>x) continue;
			if(c[j]%2==1) continue;
			if(prime[c[i]+c[j]]!=c[i]+c[j]) continue;
			dc.add_edge(i,j,INF);
		}
	}
	res=dc.max_flow(s,t);
//	printf("%d %d %d\n",x,sum,res);
	return sum-res>=k;
}
int main()
{
	int i,l,r,mid;
	init_prime(MAX-10);
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d%d%d",&pw[i],&c[i],&lv[i]);
	l=1;
	r=n;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	if(!ck(l)) puts("-1");
	else printf("%d\n",l);
	return 0;
}

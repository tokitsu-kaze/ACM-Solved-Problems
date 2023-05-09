#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Dinic
{
	static const int N=2010;
	struct node
	{
		int from,to,cap,flow;
		node(int u,int v,int c,int f) :from(u),to(v),cap(c),flow(f){}
	};
	int s,t;
	vector<node> edge;
	vector<int> mp[N];
	int vis[N],dist[N],id[N];
	void init(int n)
	{
		edge.clear();
		for(int i=0;i<=n;i++)
		{
			mp[i].clear();
			id[i]=dist[i]=vis[i]=0;
		}
	}
	void add(int from,int to,int cap)
	{
		edge.pb(node(from,to,cap,0));
		edge.pb(node(to,from,0,0));
		int m=edge.size();
		mp[from].pb(m-2);
		mp[to].pb(m-1);
	}
	bool bfs()
	{
		int i,x;
		mem(vis,0);
		queue<int>q;
		q.push(s);
		dist[s]=0;
		vis[s]=1;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			for (i=0;i<mp[x].size();i++)
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
	int dfs(int x,int a)
	{
		if(x==t||!a)return a;
		int flow = 0, f;
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
	int maxflow(int _s,int _t)
	{
		s=_s;
		t=_t;
		int res=0;
		while(bfs())
		{
			mem(id,0);
			res+=dfs(s,INF);
		}
		return res;
	}
}dc; 
void go()
{
	int n,f,d,i,j,x,s,t;
	while(~scanf("%d%d%d",&n,&f,&d))
	{
		dc.init(1200);
		s=1099;
		t=1100;
		for(i=1;i<=n;i++) dc.add(i,i+200,1);
		for(i=1;i<=f;i++) dc.add(s,i+400,1);
		for(i=1;i<=d;i++) dc.add(i+600,t,1);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&f,&d);
			while(f--)
			{
				scanf("%d",&x);
				dc.add(x+400,i,1);
			}
			while(d--)
			{
				scanf("%d",&x);
				dc.add(i+200,x+600,1);
			}
		}
		printf("%d\n",dc.maxflow(s,t));
	}
}
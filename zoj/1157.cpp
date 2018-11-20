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
	static const int N=10010;
	struct node
	{
		int from,to,cap,flow;
		node(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
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
	int n,m,k,tot,i,s,t,T;
	char a[111],b[111];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		tot=0;
		map<string,int> ha;
		dc.init(2000);
		s=1998;
		t=1999;
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			if(!ha.count(a)) ha[a]=++tot;
			dc.add(s,ha[a],1);
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%s%s",a,b);
			if(!ha.count(a))
			{
				ha[a]=++tot;
				dc.add(ha[a]+400,t,1);
			}
			if(!ha.count(b)) ha[b]=++tot;
			dc.add(ha[b],ha[a]+400,1);
		}
		scanf("%d",&k);
		for(i=0;i<k;i++)
		{
			scanf("%s%s",a,b);
			if(!ha.count(a)) ha[a]=++tot;
			if(!ha.count(b)) ha[b]=++tot;
			dc.add(ha[b],ha[a],INF);
		}
		printf("%d\n",m-dc.maxflow(s,t));
		if(T) puts("");
	}
}

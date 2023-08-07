////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-05 23:07:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3549
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:1808KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=10+10;
const ll mod=1e9+7;
struct Dinic
{
	struct node
	{
		int from,to,cap,flow;
		node(int u,int v,int c,int f) :from(u),to(v),cap(c),flow(f){}
	};
	int s,t;
	vector<node> edge;
	vector<int> mp[MAX];
	int vis[MAX],dist[MAX],id[MAX];
	void init(int n)
	{
		int i;
		edge.clear();
		for(i=1;i<=n;i++)
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
		for (int &i=id[x];i<mp[x].size();i++)
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
	int maxflow(int s,int t)
	{
		this->s=s;
		this->t=t;
		int res=0;
		while(bfs())
		{
			mem(id,0);
			res+=dfs(s,INF);
		}
		return res;
	}
}dc;
int main()
{
	int t,n,m,i,a,b,c,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		dc.init(n);
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			dc.add(a,b,c);
		}
		printf("Case %d: %d\n",cas++,dc.maxflow(1,n));  
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
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
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct MCMF
{
	#define type int
	#define inf INF
	static const int N=2020;
	struct node
	{
		int from,to;
		type cap,flow,cost;
		node(){}
		node(int u,int v,type c,type f,type co):from(u),to(v),cap(c),flow(f),cost(co){}
	};
	int n,s,t;
	vector<node> edge;
	vector<int> mp[N];
	int vis[N],id[N];
	type d[N],a[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		edge.clear();
	}
	void add_edge(int from,int to,type cap,type cost=0)
	{
		edge.pb(node(from,to,cap,0,cost));
		edge.pb(node(to,from,0,0,-cost));
		int m=edge.size();
		mp[from].pb(m-2);
		mp[to].pb(m-1);
	}
	bool spfa(type& flow,type& cost)
	{
		for(int i=0;i<=n;i++)
		{
			d[i]=inf;
			vis[i]=0;
		}
		d[s]=0;vis[s]=1;id[s]=0;a[s]=inf;
		queue<int> q;
		q.push(s);
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			vis[x]=0;
			for(int i=0;i<mp[x].size();i++)
			{
				node& e=edge[mp[x][i]];
				int to=e.to;
				if(e.cap>e.flow&&d[to]>d[x]+e.cost)
				{ 
					d[to]=d[x]+e.cost;
					a[to]=min(a[x],e.cap-e.flow);
					id[to]=mp[x][i];
					if(!vis[to])
					{
						vis[to]=1;
						q.push(to);
					}
				}
			}
		}
		if(d[t]==inf) return false;
		flow+=a[t];
		cost+=a[t]*d[t];
		int x=t;
		while(x!=s)
		{
			edge[id[x]].flow+=a[t];
			edge[id[x]^1].flow-=a[t];
			x=edge[id[x]].from;
		}
		return true;
	}
	pair<type,type> mincost_maxflow(int _s,int _t)
	{
		type flow=0,cost=0;
		s=_s;
		t=_t;
		while(spfa(flow,cost));
		return MP(cost,flow);
	}
	#undef type
	#undef inf
}wa;
void go()
{
	int a,b,i,j,sq,s,t;
	while(~scanf("%d%d",&a,&b))
	{
		s=2002;
		t=s+1;
		wa.init(t);
		for(i=a;i<=b;i++)
		{
			for(j=i+1;j<=b;j++)
			{
				sq=(int)sqrt(j*j-i*i+0.5);
				if(j*j-i*i==sq*sq&&__gcd(i,sq)==1)
				{
					wa.add_edge(i,j+1000,1,-(i+j));
					wa.add_edge(j,i+1000,1,-(i+j));
				}
			}
		}
		for(i=a;i<=b;i++)
		{
			wa.add_edge(s,i,1,0);
			wa.add_edge(i+1000,t,1,0);
		}
		PII res=wa.mincost_maxflow(s,t);
		printf("%d %d\n",res.se/2,-res.fi/2);
	}
}

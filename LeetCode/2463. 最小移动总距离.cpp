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
typedef vector<string> VS;
/************* define end  *************/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
void assert_lr(ll x,ll l,ll r) {assert(x>=l&&x<=r);};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
struct MCMF_dij
{
	#define type ll
	#define inf LLINF
	#define PTI pair<type,int>
	static const int N=1000;
	struct node
	{
		int from,to;
		type flow,cost;
		node(){}
		node(int u,int v,type f,type co):from(u),to(v),flow(f),cost(co){}
	};
	int n,s,t,id[N],vis[N];
	vector<node> edge;
	vector<int> mp[N];
	type dis[N],h[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		edge.clear();
	}
	void add_edge(int from,int to,type cap,type cost=0)
	{
		edge.pb(node(from,to,cap,cost));
		edge.pb(node(to,from,0,-cost));
		int m=edge.size();
		mp[from].pb(m-2);
		mp[to].pb(m-1);
	}
	void spfa()
	{
		int i,x,to;
		for(i=0;i<=n;i++)
		{
			h[i]=inf;
			vis[i]=0;
		}
		queue<int> q;
		q.push(s);
		h[s]=0;
		vis[s]=1;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			vis[x]=0;
			for(i=0;i<sz(mp[x]);i++)
			{
				node &e=edge[mp[x][i]];
				to=e.to;
				if(e.flow>0&&h[to]>h[x]+e.cost)
				{ 
					h[to]=h[x]+e.cost;
					if(!vis[to])
					{
						vis[to]=1;
						q.push(to);
					}
				}
			}
		}
	}
	bool dij()
	{
		int i,to;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		dis[s]=0;
		id[s]=0;
		priority_queue<PTI ,vector<PTI>,greater<PTI> > q;
		q.push(MP(type(0),s));
		while(!q.empty())
		{
			PTI x=q.top();
			q.pop();
			if(vis[x.se]) continue;
			vis[x.se]=1;
			for(i=0;i<sz(mp[x.se]);i++)
			{
				node& e=edge[mp[x.se][i]];
				to=e.to;
				type now_cost=e.cost+h[x.se]-h[to];
				if(e.flow>0&&dis[to]>dis[x.se]+now_cost)
				{ 
					dis[to]=dis[x.se]+now_cost;
					e.from=x.se;
					id[to]=mp[x.se][i];
					if(!vis[to]) q.push(MP(dis[to],to));
				}
			}
		}
		return dis[t]!=inf;
	}
	pair<type,type> mincost_maxflow(int _s,int _t)
	{
		int i;
		type flow=0,cost=0;
		s=_s;
		t=_t;
		spfa();
		while(dij())
		{
			for(i=0;i<=n;i++)
			{
				if(dis[i]==inf) continue;
				h[i]+=dis[i];
			}
			type new_flow=inf;
			for(i=t;i!=s;i=edge[id[i]].from)
			{
				new_flow=min(new_flow,edge[id[i]].flow);
			}
			for(i=t;i!=s;i=edge[id[i]].from)
			{
				edge[id[i]].flow-=new_flow;
				edge[id[i]^1].flow+=new_flow;
			}
			flow+=new_flow;
			cost+=new_flow*h[t];
		}
		return MP(cost,flow);
	}
	#undef type
	#undef inf
	#undef PTI
}mcmf; // upper: O(nm + max_flow*mlogm)
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int i,j,n;
        int s,t;
        s=800;
        t=s+1;
    	n=sz(robot)+5;
    	mcmf.init(t);
    	for(i=0;i<sz(robot);i++)
    	{
    		mcmf.add_edge(s,i+1,1,0);
    		mcmf.add_edge(i+1,n+i+1,1,0);
    		mcmf.add_edge(i+1,2*n+i+1,1,0);
    		for(j=0;j<sz(factory);j++)
    		{
    			if(robot[i]>=factory[j][0]) mcmf.add_edge(n+i+1,500+j,1,robot[i]-factory[j][0]);
    			else mcmf.add_edge(2*n+i+1,500+j,1,factory[j][0]-robot[i]);
			}
		}
		for(i=0;i<sz(factory);i++) mcmf.add_edge(500+i,t,factory[i][1],0);
		return mcmf.mincost_maxflow(s,t).fi;
		
    }
};

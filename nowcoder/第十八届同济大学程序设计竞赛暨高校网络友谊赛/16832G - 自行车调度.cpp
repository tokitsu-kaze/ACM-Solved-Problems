#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
	//inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
	inline char nc(){
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if(p1==pend){
			p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if(pend==p1){IOerror=1;return -1;}
		}
		return *p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	template<class T> inline bool read(T &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(sign)x=-x;
		return true;
	}
	inline bool read(double &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(ch=='.'){
			double tmp=1; ch=nc();
			for(;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
		}
		if(sign)x=-x;
		return true;
	}
	inline bool read(char *s){
		char ch=nc();
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		for(;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
		*s=0;
		return true;
	}
	inline bool read(char &c){
		for(c=nc();blank(c);c=nc());
		if(IOerror){c=-1;return false;}
		return true; 
	}
	template<class T,class... U>bool read(T& h,U&... t){return read(h)&&read(t...);}
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
/************* debug begin *************/
string to_string(string s){return '"'+s+'"';}
string to_string(const char* s){return to_string((string)s);}
string to_string(const bool& b){return(b?"true":"false");}
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
template<class A,class B>string to_string(pair<A,B> p){return "("+to_string(p.first)+", "+to_string(p.second)+")";}
template<class A>string to_string(const vector<A> v){
	int f=1;string res="{";for(const auto x:v){if(!f)res+= ", ";f=0;res+=to_string(x);}res+="}";
	return res;
}
void debug_out(){puts("");}
template<class T,class... U>void debug_out(const T& h,const U&... t){cout<<" "<<to_string(h);debug_out(t...);}
#ifdef tokitsukaze 
#define debug(...) cout<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__);
#else
#define debug(...) 233;
#endif
/*************  debug end  *************/
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
/************* define end  *************/
void read(int *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(ll *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(double *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
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
const int MAX=505+10;
const ll mod=998244353;
/*********************************  head  *********************************/
struct node
{
	int id;
	ll v;
	node(){}
	node(int a,int b) :id(a),v(b){}
	friend bool operator <(node a,node b){return a.v>b.v;}
};
vector<node> mp[MAX];
bool flag[MAX];
ll dis[MAX][MAX];
void dij(int s,int n)
{
	priority_queue<node> q;
	node t,to;
	for(int i=1;i<=n;i++)
	{
		dis[s][i]=LLINF;
		flag[i]=0;
	}
	dis[s][s]=0;
	q.push(node(s,0));
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.id]) continue;
		flag[t.id]=1;
		for(int i=0;i<sz(mp[t.id]);i++)
		{
			to=mp[t.id][i];
			if(dis[s][to.id]>dis[s][t.id]+to.v)
			{
				dis[s][to.id]=dis[s][t.id]+to.v;
				q.push(node(to.id,dis[s][to.id]));
			}
		}
	}
}
struct MCMF
{
	#define type ll
	#define inf LLINF
	#define PTI pair<type,int>
	static const int N=505;
	struct node
	{
		int from,to;
		type flow,cost;
		node(){}
		node(int u,int v,type f,type co):from(u),to(v),flow(f),cost(co){}
	};
	int n,s,t,id[N];
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
	
	bool dij(type& flow,type& cost)
	{
		for(int i=0;i<=n;i++) dis[i]=inf;
		dis[s]=0;id[s]=0;
		priority_queue<PTI ,vector<PTI>,greater<PTI> > q;
		q.push(MP(type(0),s));
		while(!q.empty())
		{
			PTI x=q.top();
			q.pop();
			if(x.fi!=dis[x.se]) continue;
			if(x.se==t) break;
			for(int i=0;i<mp[x.se].size();i++)
			{
				node& e=edge[mp[x.se][i]];
				int to=e.to;
				type now_cost=e.cost+h[x.se]-h[to];
				if(e.flow>0&&dis[to]>dis[x.se]+now_cost)
				{ 
					dis[to]=dis[x.se]+now_cost;
					q.push(MP(dis[to],to));
					e.from=x.se;
					id[to]=mp[x.se][i];
				}
			}
		}
		if(dis[t]==inf) return false;
		for(int i=0;i<=n;i++) h[i]=min(h[i]+dis[i],inf);
		type new_flow=inf;
		int x=t;
		while(x!=s)
		{
			new_flow=min(new_flow,edge[id[x]].flow);
			x=edge[id[x]].from;
		}
		flow+=new_flow;
		cost+=new_flow*h[t];
		x=t;
		while(x!=s)
		{
			edge[id[x]].flow-=new_flow;
			edge[id[x]^1].flow+=new_flow;
			x=edge[id[x]].from;
		}
		return true;
	}
	pair<type,type> mincost_maxflow(int _s,int _t)
	{
		type flow=0,cost=0;
		for(int i=0;i<=n;i++) h[i]=0;
		s=_s;
		t=_t;
		while(dij(flow,cost));
		return MP(cost,flow);
	}
	#undef type
	#undef inf
	#undef PTI
}mcmf;
/*
mcmf.init(n);
mcmf.add_edge(a,b,cap,cost);  a,b: 1~n
*/
ll a[502];
void go()
{
	int t,i,j,d,u,v,w,s,e,n,m,flag;
	read(t);
	while(t--)
	{
		read(n,m);
		read(a,1,n);
		d=0;
		for(i=1;i<=n;i++) d+=a[i];
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<=m;i++)
		{
			read(u,v,w);
			mp[u].pb(node(v,w));
			mp[v].pb(node(u,w));
		}
		if(d%n!=0)
		{
			puts("-1");
			continue;
		}
		d/=n;
		for(i=1;i<=n;i++) dij(i,n);
		s=n+1;
		e=n+2;
		mcmf.init(n+2);
		flag=0;
		ll sss=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]>d)
			{
				sss+=a[i]-d;
				mcmf.add_edge(s,i,a[i]-d,0);
				for(j=1;j<=n;j++)
				{
					if(a[j]<d)
					{
						if(dis[i][j]!=LLINF)
						{
							mcmf.add_edge(i,j,LLINF,dis[i][j]);
						}
					}
				}
			}
			else
			{
				mcmf.add_edge(i,e,d-a[i],0);
			}
		}
		PLL ans=mcmf.mincost_maxflow(s,e);
	//	debug(ans) 
		if(ans.se<sss) printf("-1\n");
		else printf("%lld\n",ans.fi);
	}
} 

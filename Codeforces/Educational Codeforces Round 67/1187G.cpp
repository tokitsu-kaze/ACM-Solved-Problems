#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
//  inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;}
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
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct MCMF
{
	#define type int
	#define inf INF
	static const int N=6050;
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
}mcmf;
/*
mcmf.init(n);
mcmf.add_edge(a,b,cap,cost);  a,b: 1~n
*/
VI mp[MAX];
void go()
{
	int n,m,k,c,d,i,j,x,s,t,a,b;
	while(read(n,m,k,c,d))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		mcmf.init(n*105+10);
		s=n*100+5;
		t=n*100+6;
		for(i=1;i<=100;i++) mcmf.add_edge(i,t,k,0);
		for(i=1;i<=k;i++)
		{
			read(x);
			mcmf.add_edge(s,(x-1)*100+1,1,0);
		}
		while(m--)
		{
			read(a,b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		for(i=1;i<100;i++)
		{
			for(x=1;x<=n;x++)
			{
				mcmf.add_edge((x-1)*100+i,(x-1)*100+i+1,k,c);
				for(auto to:mp[x])
				{
					for(j=1;j<=50;j++)
					{
						mcmf.add_edge((x-1)*100+i,(to-1)*100+i+1,1,c+(2*j-1)*d);
					}
				}
			}
		}
		printf("%d\n",mcmf.mincost_maxflow(s,t).fi);
	}
}

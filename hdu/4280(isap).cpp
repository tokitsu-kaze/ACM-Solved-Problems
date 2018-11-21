#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
//	inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct ISAP
{
	static const int N=100010;
	struct node
	{
		int from,to,cap,flow;
		node(){}
		node(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
	};
	int p[N],num[N],cur[N],d[N];
	int t,s,n;
	bool vis[N];
	vector<int> mp[N];
	vector<node> edge;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			mp[i].clear();
			d[i]=INF;
			vis[i]=num[i]=cur[i]=0;
		}
		edge.clear();
	}
	void add(int from,int to,int cap)
	{
		edge.pb(node(from,to,cap,0));
		edge.pb(node(to,from,cap,0));
		int m=edge.size();
		mp[from].pb(m-2);
		mp[to].pb(m-1);
	}
	bool bfs()
	{
		queue<int> q;
		d[t]=0;
		vis[t]=1;
		q.push(t);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=0;i<mp[u].size();i++)
			{
				node &e=edge[mp[u][i]^1];
				if(!vis[e.from]&&e.cap>e.flow)
				{
					vis[e.from]=true;
					d[e.from]=d[u]+1;
					q.push(e.from);
				}
			}
		}
		return vis[s];
	}
	int augment()
	{
		int u=t,flow=INF;
		while(u!=s)
		{
			node &e=edge[p[u]];
			flow=min(flow,e.cap-e.flow);
			u=edge[p[u]].from;
		}
		u=t;
		while(u!=s)
		{
			edge[p[u]].flow+=flow;
			edge[p[u]^1].flow-=flow;
			u=edge[p[u]].from;
		}
		return flow;
	}
	int maxflow(int _s,int _t)
	{
		s=_s;
		t=_t;
		int flow=0;
		bfs();
		if(d[s]>=n) return 0;
		for(int i=0;i<n;i++)
		{
			if(d[i]<INF) num[d[i]]++;
		}
		int u=s;
		while(d[s]<n)
		{
			if(u==t)
			{
				flow+=augment();
				u=s;
			}
			bool ok=false;
			for(int i=cur[u];i<mp[u].size();i++)
			{
				node &e=edge[mp[u][i]];
				if(e.cap>e.flow&&d[u]==d[e.to]+1)
				{
					ok=true;
					p[e.to]=mp[u][i]; 
					cur[u]=i;
					u=e.to;
					break;
				}
			}
			if(!ok)
			{
				int mn=n-1;
				for(int i=0;i<mp[u].size();i++)
				{
					node &e=edge[mp[u][i]];
					if(e.cap>e.flow) mn=min(mn,d[e.to]);
				}
				if(--num[d[u]]==0) break;
				num[d[u]=mn+1]++;
				cur[u]=0;
				if(u!=s) u=edge[p[u]].from;
			}
		}
		return flow;
	}
}isap;
void go()
{
	int T,s,t,x,y,i,mx,mn,a,b,w,n,m;
	read(T);
	while(T--)
	{
		mn=INF;
		mx=-INF;
		read(n,m);
		isap.init(n);
		for(i=1;i<=n;i++)
		{
			read(x,y);
			if(x<mn)
			{
				s=i;
				mn=x;
			}
			if(x>mx)
			{
				t=i;
				mx=x;
			}
		}
		while(m--)
		{
			read(a,b,w);
			isap.add(a,b,w);
		}
		printf("%d\n",isap.maxflow(s,t));
	}
}

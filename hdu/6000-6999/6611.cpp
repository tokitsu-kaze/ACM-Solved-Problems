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
    inline bool read_line(char *s){
        char ch=nc();
        for(;blank(ch);ch=nc());
        if(IOerror)return false;
        for(;ch!='\n'&&!IOerror;ch=nc())*s++=ch;
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
typedef vector<string> VS;
/************* define end  *************/
void read(int *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(ll *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(double *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
void assert_lr(ll x,ll l,ll r) {assert(x>=l&&x<=r);};
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
struct MCMF_dij
{
	#define type int
	#define inf INF
	#define PTI pair<type,int>
	static const int N=4010;
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
	bool dij()
	{
		for(int i=0;i<=n;i++) dis[i]=inf;
		dis[s]=0;id[s]=0;
		priority_queue<PTI ,vector<PTI>,greater<PTI> > q;
		q.push(MP(type(0),s));
		while(!q.empty())
		{
			PTI x=q.top();
			q.pop();
			if(x.fi>dis[x.se]) continue;
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
		return dis[t]!=inf;
	}
	pair<type,type> mincost_maxflow(int _s,int _t)
	{
		int i;
		type flow=0,cost=0;
		for(int i=0;i<=n;i++) h[i]=0;
		s=_s;
		t=_t;
		while(dij())
		{
			for(i=0;i<=n;i++) h[i]+=dis[i];
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
}mcmf; //upper: O(nmlog(nm) + max_flow*mlogm)
int a[2020];
void go()
{
    int t,n,i,j,k,S1,S2,T;
    read(t);
    while(t--)
    {
        read(n,k);
        read(a,1,n);
        S2=n*2+5;
        S1=S2+1;
        T=S1+1;
        mcmf.init(T);
        mcmf.add_edge(S1,S2,k,0);
        for(i=1;i<=n;i++)
        {
            mcmf.add_edge(S2,i*2-1,1,0);
            mcmf.add_edge(i*2-1,i*2,1,-a[i]);
            mcmf.add_edge(i*2,T,1,0);
            for(j=i+1;j<=n;j++)
            {
                if(a[i]<=a[j]) mcmf.add_edge(i*2,j*2-1,1,0);
            }
        }
        printf("%d\n",-mcmf.mincost_maxflow(S1,T).fi);
    }
}

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
const int MAX=1e6+10;
const ll mod=998244353;
/*********************************  head  *********************************/
struct Dinic
{
    #define type int
    #define inf INF
    static const int N=2050;
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
    #undef inf
}dc; 
/*
dc.init(n);
dc.add_edge(a,b,cap); a,b: 1~n
*/
void go()
{
    int T,n,m1,m2,cnt[505],i,j,x,y,z,ok,s,t,res;
    read(T);
    while(T--)
    {
        read(n,m1,m2);
        mem(cnt,0);
        for(i=1;i<=m1;i++)
        {
            read(x,y,z);
            if(z) cnt[x]++;
            else cnt[y]++;
        }
        s=n+m2+2;
        t=s+1;
        dc.init(t);
        res=0;
        for(i=1;i<=m2;i++)
        {
            read(x,y);
            if(x==1||y==1) cnt[1]++;
            else
            {
                dc.add_edge(s,n+i,1);
                res++;
                dc.add_edge(n+i,x,1);
                dc.add_edge(n+i,y,1);
            }
        }
        ok=1;
        for(i=2;i<=n;i++)
        {
            if(cnt[1]<cnt[i]) ok=0;
            dc.add_edge(i,t,cnt[1]-cnt[i]);
        }
        if(!ok)
        {
            puts("NO");
            continue;
        }
        if(dc.max_flow(s,t)==res) puts("YES");
        else puts("NO");
    } 
}

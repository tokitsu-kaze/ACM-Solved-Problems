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
const int MAX=4e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct dsu
{
    PII st[MAX];
    int pre[MAX],top,sz[MAX];
    void init(int n)
    {
        int i;
        for(i=1;i<=n;i++)
        {
            pre[i]=i;
            sz[i]=1;
        }
        top=0;
    }
    int find(int x)
    {
        if(pre[x]==x) return x;
        return find(pre[x]);
    }
    bool merge(int a,int b)
    {
        int ra,rb;
        ra=find(a);
        rb=find(b);
        if(ra==rb) return 0;
        if(sz[ra]>sz[rb]) swap(ra,rb);
        pre[ra]=rb;
        sz[rb]+=sz[ra];
        st[top++]=MP(ra,rb);
        return 1;
    }
    void roll_back()
    {
        PII now=st[--top];
        pre[now.fi]=now.fi;
        sz[now.se]-=sz[now.fi];
    }
}dsu;
struct Segment_Tree
{
    #define type int
    int root;
    int tot,ls[MAX*31],rs[MAX*31],ql,qr,n;
    PII qv;
    vector<PII> e[MAX*31];
    void init(int _n)
    {
        n=_n;
        root=0;
        ls[0]=rs[0]=0;
        e[0].clear();
        tot=1;
    }
    int newnode()
    {
        ls[tot]=rs[tot]=0;
        e[tot].clear();
        return tot++;
    }
    void update(int l,int r,int &id)
    {
        if(!id) id=newnode();
        if(l>=ql&&r<=qr)
        {
            e[id].pb(qv);
            return;
        }
        int mid=(l+r)>>1;
        if(ql<=mid) update(l,mid,ls[id]);
        if(qr>mid) update(mid+1,r,rs[id]);
    }
    type res;
    int s,t;
    void query(int l,int r,int &id)
    {
        if(!id) return;
        int cnt=0;
        for(auto it:e[id]) cnt+=dsu.merge(it.fi,it.se);
        if(dsu.find(s)==dsu.find(t))
        {
            res+=r-l+1;
            while(cnt--) dsu.roll_back();
            return;
        }
        int mid=(l+r)>>1;
        query(l,mid,ls[id]);
        query(mid+1,r,rs[id]);
        while(cnt--) dsu.roll_back();
    }
    void upd(int l,int r,PII v)
    {
        ql=l;
        qr=r;
        qv=v;
        update(1,n,root);
    }
    type ask(int _s,int _t)
    {
        s=_s;t=_t;
        res=0;
        query(1,n,root);
        return res;
    }
    #undef type
}tr;
void go()
{
    int n,m,i,a,b,l,r;
    while(read(n,m))
    {
        tr.init(1e9);
        for(i=1;i<=m;i++)
        {
            read(a,b,l,r);
            tr.upd(l,r,MP(a,b));
        }
        dsu.init(n);
        printf("%d\n",tr.ask(1,n));
    }
}

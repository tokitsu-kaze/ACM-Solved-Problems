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
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Discretization
{
    #define type ll
    vector<type> a;
    void init(){a.clear();}
    void add(type x){a.pb(x);}
    void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
    int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
    int get_pos_less_equal_than_x(type x){return upper_bound(all(a),x)-a.begin();}
    type get_val(int pos){return a[pos-1];}
    int size(){return a.size();}
    #undef type
}d;
struct Fenwick_Tree
{
    #define type int
    type bit[MAX];
    int n;
    void init(int _n)
    {
        n=_n;
        for(int i=0;i<=n;i++) bit[i]=0;
    }
    int lowbit(int x){return x&(-x);}
    void insert(int x,type v)
    {
        while(x<=n)
        {
            bit[x]+=v;
            x+=lowbit(x);
        }
    }
    type get(int x)
    {
        type res=0;
        while(x)
        {
            res+=bit[x];
            x-=lowbit(x);
        }
        return res;
    }
    type ask(int l,int r)
    {
        debug(l,r)
        if(l-1<=0) return get(r);
        return get(r)-get(l-1);
    }
    #undef type
}tr;
int lpos[MAX],rpos[MAX],pos[MAX];
struct MO_Algorithm
{
    #define type ll
    struct query_info{int id,l,r;type v;};
    vector<query_info> qst;
    int n,q;
    type ans[MAX],res;
    void init(int _n,int _q)
    {
        qst.clear();
        n=_n;
        q=_q;
    }
    void add_query(int id,int l,int r,int v=0) {qst.pb(query_info{id,l,r,v});}
    void add(int x,int k)
    {
        debug("add",x,res)
        res+=tr.ask(lpos[x],rpos[x]);
        tr.insert(pos[x],1);
        debug(res)
    }
    void del(int x,int k)
    {
        debug("del",x,res)
        tr.insert(pos[x],-1);
        res-=tr.ask(lpos[x],rpos[x]);
        debug(res)
    }
    void work(int k)
    {
        int i,l,r,sq;
        sq=sqrt(n);
        sort(all(qst),[&](query_info a,query_info b){
            if(a.l/sq!=b.l/sq) return a.l/sq<b.l/sq;
            return a.r<b.r;
        });
        
        for(i=1;i<=q;i++) ans[i]=0;
        tr.init(sz(d));
        l=1;
        r=0;
        res=0;
        for(auto q:qst)
        {
            while(l<q.l) del(l++,k);
            while(l>q.l) add(--l,k);
            while(r<q.r) add(++r,k);
            while(r>q.r) del(r--,k);
            debug(q.l,q.r,res)
            ans[q.id]+=res;
        }
        for(i=1;i<=q;i++) printf("%lld\n",ans[i]);
    }
    #undef type
}mo;// mo.init(n,q)
int a[MAX];
void go()
{
    int n,m,k,i,l,r;
    while(read(n,m,k))
    {
        read(a,1,n);
        d.init();
        for(i=1;i<=n;i++) d.add(a[i]);
        d.add(-INF);
        d.add(INF);
        d.work();
        for(i=1;i<=n;i++)
        {
            pos[i]=d.get_pos(a[i]);
            lpos[i]=d.get_pos(a[i]-k);
            rpos[i]=d.get_pos_less_equal_than_x(a[i]+k);
        }
        mo.init(n,m);
        for(i=1;i<=m;i++)
        {
            read(l,r);
            mo.add_query(i,l,r);
        }
        mo.work(k);
    }
}

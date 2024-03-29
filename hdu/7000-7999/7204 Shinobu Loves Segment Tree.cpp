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
const int MAX=1000+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
/*
struct Segment_Tree
{
    #define type int
    #define ls (id<<1)
    #define rs (id<<1|1)
    int n,ql,qr;
    type v[MAX<<2];
    void build(int l,int r,int id)
    {
        v[id]=r-l+1;
        if(l==r) return;
        int mid=(l+r)>>1;
        build(l,mid,ls);
        build(mid+1,r,rs);
    }
    void build(int _n){n=_n;build(1,n,1);}
    #undef type
    #undef ls
    #undef rs
}tr;
void go()
{
    freopen("res.txt","w",stdout);
    
    for(int x=1;x<=10;x++)
    {
        mem(tr.v,0);
        for(int i=1;i<=30;i++)
        {
            tr.build(i);
            debug(x,i,tr.v[x])
        }
    }
}
*/
string res;
ll cal(ll x)
{
    ll l,r,mid;
    l=1;
    r=x;
    for(int i=1;i<sz(res);i++)
    {
        if(l>=r) return 0;
        mid=(l+r)>>1;
        if(res[i]=='0') r=mid;
        else l=mid+1;
    }
    return r-l+1;
}
void go()
{
    int t;
    ll n,x,l,r,mid,be1,be2,ans,bs;
    read(t);
    while(t--)
    {
        read(n,x);
        res="";
        bs=1;
        while(x)
        {
            if(x&1) res+="1";
            else res+="0";
            x/=2;
            bs*=2;
        }
        bs/=2;
        reverse(all(res));
        debug(res,bs)
        l=1;
        r=n;
        while(l<r)
        {
            mid=(l+r)>>1;
            if(cal(mid)<1) l=mid+1;
            else r=mid;
        }
        if(cal(l)==1) be1=l;
        else be1=-1;
        
        l=1;
        r=n;
        while(l<r)
        {
            mid=(l+r)>>1;
            if(cal(mid)<2) l=mid+1;
            else r=mid;
        }
        if(cal(l)==2) be2=l;
        else be2=-1;
        
        debug(be1,be2)
        
        ans=0;
        if(be1==-1)
        {
            puts("0");
            continue;
        }
        if(be2==-1)
        {
            printf("%lld\n",n-be1+1);
            continue;
        }
        ans+=be2-be1;
        ans+=(2+1+(n-be2+1)/bs)*((n-be2+1)/bs*bs)/2;
        ans+=(1+(n-be2+1)/bs+1)*(n-(be2+(n-be2+1)/bs*bs-1));
        printf("%lld\n",ans);
        
    }
}

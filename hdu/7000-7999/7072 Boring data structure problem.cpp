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
const int MAX=1e7+10;
const ll mod=998244353;
/*********************************  head  *********************************/
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
    int n,ql,qr;
    type v[MAX<<2],qv;
    short tag[MAX<<2];
    void pushup(int id)
	{
	    v[id]=v[ls]+v[rs];
	}
    void pushdown(int l,int r,int id)
	{
	    if(!tag[id]) return;
	    tag[ls]+=tag[id];
	    tag[rs]+=tag[id];
	    int mid=(l+r)>>1;
	    v[ls]+=(mid-l+1)*tag[id];
	    v[rs]+=(r-mid)*tag[id];
	    tag[id]=0;
	}
    void build(int l,int r,int id)
	{
	    tag[id]=0;
	    if(l==r)
		{
		    v[id]=0;
		    return;
		}
	    int mid=(l+r)>>1;
	    build(l,mid,ls);
	    build(mid+1,r,rs);
	    pushup(id);
	}
    void update(int l,int r,int id)
	{
	    if(l>=ql&&r<=qr)
		{
		    v[id]+=(r-l+1)*qv;
		    tag[id]+=qv;
		    return;
		}
	    pushdown(l,r,id);
	    int mid=(l+r)>>1;
	    if(ql<=mid) update(l,mid,ls);
	    if(qr>mid) update(mid+1,r,rs);
	    pushup(id);
	}
    type res;
    void query(int l,int r,int id)
	{
	    if(res!=-1) return;
	    if(l==r)
		{
		    if(qv==v[id]) res=l;
		    else qv-=v[id];
		    return;
		}
	    pushdown(l,r,id);
	    int mid=(l+r)>>1;
	    if(l>=ql&&r<=qr)
		{
		    if(v[id]<qv)
			{
			    qv-=v[id];
			    return;
			}
		    if(v[ls]<qv)
			{
			    qv-=v[ls];
			    query(mid+1,r,rs);
			}
		    else query(l,mid,ls);
		}
	    else
		{
		    if(ql<=mid) query(l,mid,ls);
		    if(qr>mid) query(mid+1,r,rs);
		}
	}
    void build(int _n){n=_n;build(1,n,1);}
    void upd(int l,int r,type v)
	{
	    ql=l;
	    qr=r;
	    qv=v;
	    update(1,n,1);
	}
    type ask(int l,int r,type v)
	{
	    ql=l;
	    qr=r;
	    qv=v;
	    res=-1;
	    query(1,n,1);
	    return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
char op[MAX][2];
int x[int(1.5e6)+10],pos[MAX],num[MAX];
void go()
{
    int n,i,lcnt,rcnt,cnt,now,posl,posr,nowl,nowr,g_tot,g_idx;
    while(read(n))
	{
	    lcnt=rcnt=0;
	    g_tot=0;
	    for(i=1;i<=n;i++)
		{
		    read(op[i]);
		    if(op[i][0]=='G') read(x[g_tot++]);
		    else if(op[i][0]=='L') lcnt++;
		    else if(op[i][0]=='R') rcnt++;
		}
	    now=1;
	    cnt=0;
	    nowl=posl=lcnt;
	    nowr=posr=lcnt+1;
	    tr.build(lcnt+rcnt);
	    g_idx=0;
	    for(i=1;i<=n;i++)
		{
		    if(op[i][0]=='L')
			{
			    pos[now]=nowl;
			    num[nowl]=now;
			    nowl--;
			    cnt++;
			    now++;
			}
		    else if(op[i][0]=='R')
			{
			    pos[now]=nowr;
			    num[nowr]=now;
			    nowr++;
			    cnt++;
			    now++;
			}
		    else
			{
			    if(nowl<posl) tr.upd(nowl+1,posl,1);
			    if(nowr>posr) tr.upd(posr,nowr-1,1);
			    posl=nowl;
			    posr=nowr;
			    if(op[i][0]=='G')
				{
				    tr.upd(pos[x[g_idx]],pos[x[g_idx]],-1);
				    g_idx++;
				    cnt--;
				}
			    else
				{
				    printf("%d\n",num[tr.ask(posl+1,posr-1,cnt/2+1)]);
				}
			}
		}
	}
}


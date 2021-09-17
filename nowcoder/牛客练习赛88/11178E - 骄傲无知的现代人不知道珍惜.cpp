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
//const ll mod=998244353;
ll mod;
/*********************************  head  *********************************/
void assert_lr(int x,int l,int r){assert(x>=l&&x<=r);}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll g,t;
	g=exgcd(b,a%b,x,y);
	t=x;
	x=y;
	y=t-a/b*y;
	return g;
}
namespace exCRT
{
	ll excrt(VL &a,VL &b)//res=a_i(mod b_i)
	{
	    ll x,y,k,g,c,p,res,bg;
	    assert(sz(a)==sz(b));
	    assert(sz(a)>0);
	//    debug(a)
	//    debug(b)
	    p=b[0];
		res=a[0];
	    for(int i=1;i<sz(a);i++)
	    {
	        c=(a[i]-res%b[i]+b[i])%b[i];
	        g=exgcd(p,b[i],x,y);
			bg=b[i]/g;
	        if(c%g!=0) return -1;
	        x=(x*(c/g))%bg;
	        res+=x*p;
	        p*=bg;
	        res=(res%p+p)%p;
	    }
	    return (res%p+p)%p;
	}
};
namespace exLucas
{
	ll pow2(ll a,ll b,ll p)
	{
		ll res=1;
		while(b>0)
		{
			if(b&1) res=res*a%p;
			a=a*a%p;
			b>>=1;
		}
		return res;
	}
	ll inv(ll a,ll p)
	{
		ll g,x,y,res;
		g=exgcd(a,p,x,y);
		res=(g==1?(x+p)%p:-1);
		assert(res!=-1);
		return res;
	}
	map<ll,pair<VL,VL> > mp;
	map<PLL,VL > fac;
	void init(VL mod_list)
	{
		ll i,j,p;
		mp.clear();
		fac.clear();
		for(auto mod_i:mod_list)
		{
			p=mod_i;
			VL a,b;
			for(i=2;i*i<=p;i++)
			{
				if(p%i) continue;
				b.pb(1LL);
				while(p%i==0) b[sz(b)-1]*=i,p/=i;
				a.pb(i);
			}
			if(p>1) a.pb(p),b.pb(p);
			mp[mod_i]=MP(a,b);
			for(i=0;i<sz(a);i++)
			{
				if(fac.count(MP(a[i],b[i]))) continue;
				VL fac_tmp=VL(b[i]+1);
				fac_tmp[0]=1;
				for(j=1;j<=b[i];j++)
				{
					if(j%a[i]) fac_tmp[j]=fac_tmp[j-1]*j%b[i];
					else fac_tmp[j]=fac_tmp[j-1];
				}
				fac[MP(a[i],b[i])]=fac_tmp;
		//		debug(a[i],b[i])
			}
		}
	}
	ll cal_fac(ll n,ll x,ll p)
	{
		if(!n) return 1LL;
		ll res=1;
		assert(fac.count(MP(x,p)));
		res=res*fac[MP(x,p)][p-1]%p;
		res=pow2(res,n/p,p);
		res=res*fac[MP(x,p)][n%p]%p;
		return res*cal_fac(n/x,x,p)%p;
	}
	ll multilucas(ll n,ll m,ll x,ll p)
	{
		if(m>n) return 0;
		ll i,cnt;
		cnt=0;
		for(i=n;i;i/=x) cnt+=i/x;
		for(i=m;i;i/=x) cnt-=i/x;
		for(i=n-m;i;i/=x) cnt-=i/x;
		return pow2(x,cnt,p)*             \
			   cal_fac(n,x,p)%p*          \
			   inv(cal_fac(m,x,p),p)%p*   \
			   inv(cal_fac(n-m,x,p),p)%p;
	}
	ll C(ll n,ll m,ll p)
	{
		if(m>n||m<0||n<0) return 0;
		ll i,res;
		VL a,b,resa;
		assert(mp.count(p));
		a=mp[p].fi;
		b=mp[p].se;
	//	debug(n,m)
		for(i=0;i<sz(a);i++) resa.pb(multilucas(n,m,a[i],b[i]));
		res=exCRT::excrt(resa,b);
		assert(res!=-1);
		return res;
	}
};
ll ans[MAX],val[MAX];
struct dsu
{
	PII st[MAX];
	int pre[MAX],top;
	ll sum[MAX],res[MAX],sz[MAX];
	multiset<ll> ans;
	void init(int n)
	{
		int i;
		ans.clear();
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
			sum[i]=val[i];
			res[i]=exLucas::C(sum[i],sz[i],mod);
	//		debug(i,res[i])
			ans.insert(res[i]);
		}
		top=0;
	}
	int find(int x)
	{
		while(x!=pre[x]) x=pre[x];
		return x;
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra==rb) return 0;
		if(sz[ra]>sz[rb]) swap(ra,rb);
		pre[ra]=rb;
		ans.erase(ans.find(res[ra]));
		ans.erase(ans.find(res[rb]));
		sz[rb]+=sz[ra];
		sum[rb]=(sum[rb]+sum[ra]);
		res[rb]=exLucas::C(sum[rb],sz[rb],mod);
		ans.insert(res[rb]);
		st[top++]=MP(ra,rb);
		return 1;
	}
	void roll_back()
	{
		PII now=st[--top];
		pre[now.fi]=now.fi;
		ans.erase(ans.find(res[now.se]));
		sz[now.se]-=sz[now.fi];
		sum[now.se]=((sum[now.se]-sum[now.fi]));
		assert(sum[now.se]>=0);
		res[now.se]=exLucas::C(sum[now.se],sz[now.se],mod);
		ans.insert(res[now.se]);
		ans.insert(res[now.fi]);
	}
}dsu;
PII e[MAX];
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type qv;
	VI v[MAX<<2];
	void build(int l,int r,int id)
	{
		v[id].clear();
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			v[id].pb(qv);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	void dfs(int l,int r,int id)
	{
		int cnt=0;
		for(auto it:v[id]) cnt+=dsu.merge(e[it].fi,e[it].se);
		if(l==r)
		{
			ans[l]=*dsu.ans.rbegin();
			while(cnt--) dsu.roll_back();
			return;
		}
		int mid=(l+r)>>1;
		dfs(l,mid,ls);
		dfs(mid+1,r,rs);
		while(cnt--) dsu.roll_back();
	}
	#undef type
	#undef ls
	#undef rs
}tr;
int l[MAX],r[MAX];
void go()
{
	int n,q,i,op,tot,k;
	exLucas::init(VL{4580564,1145141,100160063,102101809});
	while(read(n,q,mod))
	{
		assert_lr(n,1,8e4);
		assert_lr(q,1,8e4);
		for(i=1;i<=n;i++)
		{
			read(val[i]);
			assert_lr(val[i],0,2e9);
		}
		tot=0;
		for(i=1;i<=q;i++)
		{
			read(op);
			if(op==0)
			{
				tot++;
				read(e[tot].fi,e[tot].se);
				l[tot]=i;
				r[tot]=q;
			}
			else if(op==1)
			{
				read(k);
				assert(k>=0&&k<=tot);
				assert(r[k]==q);
				r[k]=i-1;
			}
			else assert(0);
		}
		tr.build(q);
		for(i=1;i<=tot;i++) tr.upd(l[i],r[i],i);
		dsu.init(n);
		tr.dfs(1,q,1);
		for(i=1;i<=q;i++) printf("%lld\n",ans[i]);
	}
}

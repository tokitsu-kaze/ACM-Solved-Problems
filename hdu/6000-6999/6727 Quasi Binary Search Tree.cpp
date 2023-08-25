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
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int d[MAX],sz[MAX],to[MAX][2],mn[MAX];
void dfs1(int x)
{
	mn[x]=x;
	sz[x]=1;
	if(to[x][0])
	{
		dfs1(to[x][0]);
		sz[x]+=sz[to[x][0]];
		mn[x]=min(mn[x],mn[to[x][0]]);
	}
	if(to[x][1])
	{
		dfs1(to[x][1]);
		sz[x]+=sz[to[x][1]];
		mn[x]=min(mn[x],mn[to[x][1]]);
	}
}
int res[MAX];
void dfs(int x,int l,int r)
{
	if(!x) return;
	if(sz[x]==1)
	{
		assert(l==r);
		res[x]=l;
		return;
	}
	int tmpl,tmpr;
	tmpl=sz[to[x][0]];
	tmpr=sz[to[x][1]];
	if(!tmpl)
	{
		if(x<mn[to[x][1]])
		{
			dfs(to[x][1],l+1,r);
			res[x]=l;
			return;
		}
		else
		{
			dfs(to[x][1],l,r-1);
			res[x]=r;
			return;
		}
	}
	else if(!tmpr)
	{
		if(x<mn[to[x][0]])
		{
			dfs(to[x][0],l+1,r);
			res[x]=l;
			return;
		}
		else
		{
			dfs(to[x][0],l,r-1);
			res[x]=r;
			return;
		}
	}
	else
	{
		if(mn[to[x][0]]<mn[to[x][1]]&&mn[to[x][0]]<x)
		{
			dfs(to[x][0],l,l+tmpl-1);
			dfs(to[x][1],r-tmpr+1,r);
			res[x]=l+tmpl;
			return;
		}
		else if(mn[to[x][1]]<mn[to[x][0]]&&mn[to[x][1]]<x)
		{
			dfs(to[x][1],l,l+tmpr-1);
			dfs(to[x][0],r-tmpl+1,r);
			res[x]=l+tmpr;
			return;
		}
		else if(x<mn[to[x][0]]&&x<mn[to[x][1]])
		{
			if(tmpl<tmpr)
			{
				dfs(to[x][0],l,l+tmpl-1);
				dfs(to[x][1],r-tmpr+1,r);
				res[x]=l+tmpl;
			}
			else if(tmpr<tmpl)
			{
				dfs(to[x][1],l,l+tmpr-1);
				dfs(to[x][0],r-tmpl+1,r);
				res[x]=l+tmpr;
			}
			else
			{
				if(mn[to[x][0]]<mn[to[x][1]])
				{
					dfs(to[x][0],l,l+tmpl-1);
					dfs(to[x][1],r-tmpr+1,r);
					res[x]=l+tmpl;
				}
				else
				{
					dfs(to[x][1],l,l+tmpr-1);
					dfs(to[x][0],r-tmpl+1,r);
					res[x]=l+tmpr;
				}
			}
			return;
		}
	}
}
ll tp[MAX];
void go()
{
	int t,n,i,rt;
	ll ans;
	read(t);
	while(t--)
	{
		read(n);
		tp[0]=1;
		for(i=1;i<=n;i++)
		{
			d[i]=0;
			tp[i]=tp[i-1]*233%mod;
		}
		for(i=1;i<=n;i++)
		{
			read(to[i][0],to[i][1]);
			d[to[i][0]]++;
			d[to[i][1]]++;
		}
		for(i=1;i<=n;i++)
		{
			if(!d[i])
			{
				rt=i;
				break;
			}
		}
		mn[0]=INF;
		dfs1(rt);
		dfs(rt,1,n);
		ans=0;
		for(i=1;i<=n;i++)
		{
	//		debug(i,res[i])
			ans=(ans+(res[i]^i)*tp[i]%mod)%mod;
		}
		printf("%lld\n",ans);
	}
}

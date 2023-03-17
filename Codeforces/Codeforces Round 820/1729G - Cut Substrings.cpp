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
VL good_hash_prime={50331653,100663319,201326611,402653189,805306457,1610612741};
VL get_hash_prime(int cnt=2)
{
	assert(cnt<=sz(good_hash_prime));
	srand(time(0));
	random_shuffle(all(good_hash_prime));
	return VL(good_hash_prime.begin(),good_hash_prime.begin()+cnt);
}
struct hash_table
{
	ll seed,p;
	ll Hash[MAX],tmp[MAX];
	void set(ll _seed,ll _p)
	{
		seed=_seed;
		p=_p;
	}
	void work(char *s,int n)
	{
		tmp[0]=1;
		Hash[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=tmp[i-1]*seed%p;
			Hash[i]=(Hash[i-1]*seed+s[i])%p;//may need change
		}
	}
	ll get(int l,int r)
	{
		return ((Hash[r]-Hash[l-1]*tmp[r-l+1])%p+p)%p;
	}
}has[2],hat[2];
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x){return pow2(x,mod-2);}
int dp[505][505],n;
ll cnt[505][505];
string s,t;
int dfs(int l,int r)
{
	int now;
	if(dp[l][r]!=INF) return dp[l][r];
	cnt[l][r]=1;
	if(l>r) return dp[l][r]=0;
	if(l<1||r>n) return dp[l][r]=0;
	if(r-l+1<sz(t)) return dp[l][r]=0;
	for(int i=l;i+sz(t)-1<=r;i++)
	{
		if(has[0].get(i,i+sz(t)-1)==hat[0].get(1,sz(t))&&
		   has[1].get(i,i+sz(t)-1)==hat[1].get(1,sz(t)))
		{
			dfs(l,i-1);
			dfs(i+sz(t),r);
			now=1+dp[l][i-1]+dp[i+sz(t)][r];
			if(now<dp[l][r])
			{
				dp[l][r]=now;
				cnt[l][r]=cnt[l][i-1]*cnt[i+sz(t)][r]%mod;
			}
			else if(now==dp[l][r])
			{
				cnt[l][r]=(cnt[l][r]+cnt[l][i-1]*cnt[i+sz(t)][r])%mod;
			}
		}
			
	}
	if(dp[l][r]==INF) dp[l][r]=0;
	else if(dp[l][r]) cnt[l][r]=cnt[l][r]*inv(dp[l][r])%mod;
	return dp[l][r];
}
void go()
{
	int q,i;
	char tmp_s[505],tmp_t[505];
	read(q);
	while(q--)
	{
		read(tmp_s+1);
		read(tmp_t+1);
		n=strlen(tmp_s+1);
		s=" "+string(tmp_s+1);
		t=string(tmp_t+1);
		VL p=get_hash_prime(2);
		for(i=0;i<2;i++)
		{
			has[i].set(13331,p[i]);
			hat[i].set(13331,p[i]);
			has[i].work((char *)tmp_s,n);
			hat[i].work((char *)tmp_t,sz(t));
		}
		mem(dp,0x3f);
		mem(cnt,0);
		dfs(1,n);
		printf("%d %lld\n",dp[1][n],cnt[1][n]);
	}
}


